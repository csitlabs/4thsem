USE HospitalDb;

-- Alter Patients Table to add new fields
ALTER TABLE Patients
ADD Blood_Group VARCHAR(5),
    Email VARCHAR(100);

-- Update existing records with relevant data for the new fields
UPDATE Patients
SET Blood_Group = 'A+',
    Email = 'alicejohnson@example.com'
WHERE Patient_Id = 1;

UPDATE Patients
SET Blood_Group = 'B-',
    Email = 'bobsmith@example.com'
WHERE Patient_Id = 2;

UPDATE Patients
SET Blood_Group = 'AB+',
    Email = 'alicejohnson@example.com'
WHERE Patient_Id = 3;

UPDATE Patients
SET Blood_Group = 'O-',
    Email = 'charliebrown@example.com'
WHERE Patient_Id = 4;

UPDATE Patients
SET Blood_Group = 'A+',
    Email = 'davidlee@example.com'
WHERE Patient_Id = 5;

UPDATE Patients
SET Blood_Group = 'B-',
    Email = 'evahernandez@example.com'
WHERE Patient_Id = 6;

UPDATE Patients
SET Blood_Group = 'AB+',
    Email = 'bobsmith@example.com'
WHERE Patient_Id = 7;

UPDATE Patients
SET Blood_Group = 'O-',
    Email = 'gracetaylor@example.com'
WHERE Patient_Id = 8;

UPDATE Patients
SET Blood_Group = 'A+',
    Email = 'harrybrown@example.com'
WHERE Patient_Id = 9;

UPDATE Patients
SET Blood_Group = 'B-',
    Email = 'isabelkim@example.com'
WHERE Patient_Id = 10;