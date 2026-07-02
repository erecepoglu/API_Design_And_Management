const fs = require("fs")

const employees = [];
employees.push({
    "name": "Ahmed",
    "salary": 9000,
    "id": 1001
},{
    "name": "Ali",
    "salary": 9000,
    "id": 1002
},{
   "name": "Hussin",
   "salary": 20000,
   "id": 1003 
})

fs.writeFileSync("jsondata.json",JSON.stringify(employees))
console.log(JSON.stringify(employees))