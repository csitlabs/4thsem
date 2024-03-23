SELECT * FROM Patients WHERE Blood_Group = 'O-';

SELECT * FROM Rooms WHERE Capacity = 4;

SELECT * FROM Doctors WHERE Department_Id = (
    SELECT Department_Id FROM Departments WHERE Name = 'Neurology'
);

SELECT a.Appointment_Id, d.Name AS Doctor_Name, p.Name AS Patient_Name, a.Date_Time
FROM Appointments a
INNER JOIN Doctors d ON a.Doctor_Id = d.Doctor_Id
INNER JOIN Patients p ON a.Patient_Id = p.Patient_Id
WHERE d.Name = 'Dr. John Smith';

SELECT Patients.Name AS Patient_Name, Rooms.Room_No
FROM Patients
LEFT JOIN Rooms ON Patients.Room_Id = Rooms.Room_Id;
