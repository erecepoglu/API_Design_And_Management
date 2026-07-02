const Schema = require("./employee_pb");
const fs = require("fs")

const hussein = new Schema.Employee();
hussein.setId(1001);
hussein.setName("Hussein");
hussein.setSalary(20000);

const ahmed = new Schema.Employee();
ahmed.setId(1002);
ahmed.setName("Ahmed");
ahmed.setSalary(30000);

const ali = new Schema.Employee();
ali.setId(1003);
ali.setName("Ali");
ali.setSalary(30000);



const employees = new Schema.Employees();
employees.addEmployees(hussein);
employees.addEmployees(ali);
employees.addEmployees(ahmed);

const bytes = employees.serializeBinary();
fs.writeFileSync("employeesbinary",bytes);
console.log(`My name is ${ali.getName()}`);
console.log(`Binary:\n${bytes}`)