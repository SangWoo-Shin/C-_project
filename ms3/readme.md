CustomerOrder Module

A CustomerOrder object manages a single order on the assembly line and contains the following information:

The CustomerOrder class has the following structure:

Item Definition

struct Item
{
    std::string m_itemName;
    size_t m_serialNumber{0};
    bool m_isFilled{false};

    Item(const std::string& src) : m_itemName(src) {};
};
Instance Variables

std::string m_name – the name of the customer (e.g., John, Sara, etc)
std::string m_product – the name of the product being assembled (e.g., Desktop, Laptop, etc)
size_t m_cntItem – a count of the number of items in the customer's order
Item** m_lstItem – a dynamically allocated array of pointers. Each element of the array points to a dynamically allocated object of type Item (see below). This is the resource that your class must manage.
Class Variable

static size_t m_widthField – the maximum width of a field, used for display purposes
Member Functions

default constructor

a custom 1-argument constructor that takes a reference to an unmodifiable string. This constructor uses a local Utilities object to extract the tokens from the string and populate the current instance. The fields in the string are (separated by a delimiter):

Customer Name
Order Name
the list of items making up the order (at least one item)
After finishing extraction, this constructor updates CustomerOrder::m_widthField if the current value is smaller than the value stored in Utilities::m_widthField.

a CustomerOrder object should not allow copy operations. The copy constructor should throw an exception if called and the copy operator= should be deleted.

a move constructor. This constructor should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the declaration and the definition.

a move assignment operator. This operator should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the declaration and the definition.

a destructor

bool isOrderFilled() const – returns true if all the items in the order have been filled; false otherwise

bool isItemFilled(const std::string& itemName) const – returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.

void fillItem(Station& station, std::ostream& os) – this modifier fills one item in the current order that the Station specified in the first parameter handles.

if the order doesn't contain the item handled, this function does nothing
if the order contains items handled, and the Station's inventory contains at least one item, this function fills the order with one single item. It subtracts 1 from the iisFinventory and updates Item::m_serialNumber and Item::m_lled. It also prints the message Filled NAME, PRODUCT [ITEM_NAME].
if the order contains items handled but unfilled, and the inventory is empty, this function prints the message Unable to fill NAME, PRODUCT [ITEM_NAME].
all messages printed are terminated by an endline
void display(std::ostream& os) const – this query displays the state of the current object in the format (see the sample output for details)

CUSTOMER_NAME - PRODUCT
[SERIAL] ITEM_NAME - STATUS
[SERIAL] ITEM_NAME - STATUS
...
SERIAL - a field of width 6
ITEM_NAME - a field of size m_widthField
STATUS is either FILLED or TO BE FILLED
you must use IO manipulators to format this output.







































## Milestone 3

Milestone 3 implements and tests the `Workstation` and `LineManager` modules.

The `LineManager` module first configures the assembly line and then moves `CustomerOrders` along it (from start to finish).  The `LineManager` object configures the `Workstation` objects identified by the user, and moves orders along the line one step at a time. A `Workstation` is a `Station` that the `LineManager` has activated on the user's request. At each step, every `Workstation` fills one item in a `Customer Order`, if possible. The manager moves orders from station to station. Once an order has reached the end of the line, it is either complete or incomplete. An order is incomplete if one or more stations had an insufficient number of items in stock to cover that order's requests.

## `Workstation` Module

The `Workstation` module consists of three double-ended queues of `CustomerOrder` and the `Workstation` class. The queues (global variables) hold the orders at either end of the assembly line:

- `g_pending` holds the orders to be placed onto the assembly line at the first station.
- `g_completed` holds the orders that have been removed from the last station and have been completely filled.
-  `g_incomplete` holds the orders that have been removed from the last station and could not be filled completely.

Each queue is accessible outside this module's translation unit.

The `Workstation` class defines the structure of an active station on the assembly line and contains all the functionality for filling customer orders with station items.  Each `Workstation` is-a-kind-of `Station`. A `Workstation` object manages order processing for a single `Item` on the assembly line. Since a `Workstation` object represents a single location on the assembly line for filling customer orders with items, the object cannot be copied or moved. Make sure that this capability is deleted in your definition of the `Workstation` class.

The `Workstation` class includes the following additional information:

***Instance Variables***

- `m_orders` – is a double-ended-queue with `CustomerOrders` entering the back and exiting the front.  These are orders that have been placed on this station to receive service (or already received service).
- `m_pNextStation` – a pointer to the next `Workstation` on the assembly line.

***Member Functions***

- a custom 1-argument constructor -- receives a reference to an unmodifiable reference to `std::string` and passes it to the `Station` base class.  

- `void fill(std::ostream& os)` – this modifier fills the order at the front of the queue if there are `CustomerOrders` in the queue; otherwise, does nothing.

- `bool attemptToMoveOrder()` – attempts to move the order order at the front of the queue to the next station in the assembly line:
    - if the order requires no more service at this station or cannot be filled (not enough inventory), move it to the next station; otherwise do nothing
        - if there is no next station in the assembly line, then the order is moved into `g_completed` or `g_incomplete` queue
    - if an order has been moved, return `true`; `false` otherwise. 
    
- `void setNextStation(Workstation* station)` – this modifier stores the address of the referenced `Workstation` object in the pointer to the `m_pNextStation`. Parameter defaults to `nullptr`.

- `Workstation* getNextStation() const` – this query returns the address of next `Workstation`

- `void display(std::ostream& os) const` – this query inserts the name of the `Item` for which the current object is responsible into stream `os` following the format: `ITEM_NAME --> NEXT_ITEM_NAME`
    - if the current object is the last `Workstation` in the assembly line this query inserts: `ITEM_NAME --> End of Line`.
    - in either case, the message is terminated with `\n`

- `Workstation& operator+=(CustomerOrder&& newOrder)` – moves the `CustomerOrder` referenced in parameter `newOrder` to the back of the queue.




## `LineManager` Module

The `LineManager` class manages an assembly line of active stations and contains the following information:

***Instance Variables***
- `std::vector<Workstation*> m_activeLine` – the collection of workstations for the current assembly line.
- `size_t m_cntCustomerOrder` – the total number of `CustomerOrder` objects
- `Workstation* m_firstStation` - points to the first active station on the current line

***Member Functions***
- `LineManager(const std::string& file, const std::vector<Workstation*>& stations)` - this constructor receives the name of the file that identifies the active stations on the assembly line (example:  `AssemblyLine.txt`) and the collection of workstations available for configuring the assembly line.

  The file contains the linkage between workstation pairs. The format of each record in the file is `WORKSTATION|NEXT_WORKSTATION`. The records themselves are not in any particular order.

  This function stores the workstations in the order received from the file in the `m_activeLine` instance variable. It loads the contents of the file, stores the address of the next workstation in each element of the collection, identifies the first station in the assembly line and stores its address in the `m_firstStation` attribute. This function also updates the attribute that holds the total number of orders in the `g_pending` queue.  If something goes wrong, this constructor reports an error. 

  **Note**: to receive full marks, use STL algorithms throughout this function, except for iterating through the file records (one `while` loop); marks will be deducted if you use any of `for`, `while` or `do-while` loops except for iterating through the file records. 

- `void reorderStations()` - this modifier reorders the workstations present in the instance variable `m_activeLine` (loaded by the constructor) and stores the reordered collection in the same instance variable. The elements in the reordered collection start with the first station, proceeds to the next, and so forth until the end of the line. 

- `bool run(std::ostream& os)` –  this modifier performs **one** iteration of operations on all of the workstations in the current assembly line by doing the following:
    - keeps track of the current iteration number (use a local variable)
    - inserts into stream `os` the iteration number (how many times this function has been called by the client) in the format `Line Manager Iteration: COUNT<endl>`
    - moves the order at the front of the `g_pending` queue to the `m_firstStation` and remove it from the queue. This function moves only one order to the line on a single iteration.
    - for each station on the line, executes one fill operation
    - for each station on the line, attempts to move an order down the line
    - return `true` if all customer orders have been filled or cannot be filled, otherwise returns `false`.
- `void display(std::ostream& os) const` -- this query displays all active stations on the assembly line in their current order


## Tester Module

The tester module and input files are included in the repository. Do not modify any of them.

## Sample Output

Look in the file `ms3_output.txt` for the command line necessary to start the application and the expected output.


#### Submission

Create a **text** file named `reflect.txt`.  Add any comments you wish to make.

Before the due date, upload to your matrix account the following files:
- `Utilities.h`
- `Utilities.cpp`
- `Station.h`
- `Station.cpp`
- `CustomerOrder.h`
- `CustomerOrder.cpp`
- `Workstation.h`
- `Workstation.cpp`
- `LineManager.h`
- `LineManager.cpp`
- `reflect.txt`

From a command prompt, execute the following command:

```bash
~profname.proflastname/submit 345_ms3
```

and follow the instructions.

**A successful submission does not guarantee full credit!**
