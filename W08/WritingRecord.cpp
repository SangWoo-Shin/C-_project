// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        
        // TODO: Add your code here to build a list of employees
        //         using raw pointers
        
        string err;
        for(size_t i = 0; i < emp.size(); i++)
        {
            for(size_t j = 0; j < sal.size(); j++)
            {
                if(emp[i].id == sal[j].id)
                {
                    GeneratingList<EmployeeWage> tempList;
                    EmployeeWage* temp = nullptr;
                    temp = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        temp->rangeValidator();
                    }
                    catch(...) {
                        delete temp;
                        err = "*** Employees salaray range is not valid";
                        throw err;
                    }
                    if(!tempList.validationSIN(emp[i].id))
                    {
                        delete temp;
                        err = "ERROR: *** Employees SIN number is not valid";
                        throw err;
                    }
                    activeEmp += temp;
                    delete temp;
                }
            }
        }
        return activeEmp;
    }

    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal)
    {
        GeneratingList<EmployeeWage> activeEmp;
        // TODO: Add your code here to build a list of employees
        //         using smart pointers
        string err;
        for(size_t i = 0; i < emp.size(); i++)
        {
            for(size_t j = 0; j < sal.size(); j++)
            {
                if(emp[i].id == sal[j].id)
                {
                    GeneratingList<EmployeeWage> tempList;
                    std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
                    try {
                        temp->rangeValidator();
                    }
                    catch(...) {
                        err = "*** Employees salaray range is not valid";
                        throw err;
                    }
                    if(!tempList.validationSIN(emp[i].id))
                    {
                        err = "ERROR: *** Employees SIN number is not valid";
                        throw err;
                    }
                    activeEmp += temp;
                }
            }
        }
        return activeEmp;
    }
}
