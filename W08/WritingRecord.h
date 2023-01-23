// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H

