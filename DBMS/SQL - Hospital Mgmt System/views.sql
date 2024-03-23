
-- Exectute one at a time
-- Patient Info

CREATE VIEW PatientInfo AS
SELECT 
    p.Patient_Id,
    p.Name AS Patient_Name,
    p.DOB,
    p.Gender,
    p.Address,
    p.Age,
    p.Contact,
    r.Room_No,
    d.Name AS Disease_Name
FROM Patients p
INNER JOIN Rooms r ON p.Room_Id = r.Room_Id
INNER JOIN Diseases d ON p.Disease_Id = d.Disease_Id;

-- Doctor Info

CREATE VIEW DoctorInfo AS
SELECT 
    d.Doctor_Id,
    d.Name AS Doctor_Name,
    d.Specialization,
    dp.Name AS Department_Name,
    d.Contact,
    d.Email,
    d.Shift
FROM Doctors d
INNER JOIN Departments dp ON d.Department_Id = dp.Department_Id;

-- Appointment Info

CREATE VIEW AppointmentInfo AS
SELECT 
    a.Appointment_Id,
    p.Patient_Id,
    p.Name AS Patient_Name,
    dr.Doctor_Id,
    dr.Name AS Doctor_Name,
    a.Date_Time
FROM Appointments a
INNER JOIN Patients p ON a.Patient_Id = p.Patient_Id
INNER JOIN Doctors dr ON a.Doctor_Id = dr.Doctor_Id;


-- Available rooms

CREATE VIEW AvailableRooms AS
SELECT 
    dp.Department_Id,
    dp.Name AS Department_Name,
    COUNT(r.Room_Id) AS Total_Rooms,
    COUNT(CASE WHEN p.Patient_Id IS NULL THEN 1 END) AS Available_Rooms
FROM Departments dp
LEFT JOIN Rooms r ON dp.Department_Id = r.Department_Id
LEFT JOIN Patients p ON r.Room_Id = p.Room_Id
GROUP BY dp.Department_Id, dp.Name;

-- Drop available rooms views 

DROP VIEW IF EXISTS AvailableRooms;
-- DROP VIEW AvailableRooms;