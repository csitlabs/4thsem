USE HospitalDb;

INSERT INTO Diseases (Name) VALUES
('Flu'),
('Diabetes'),
('Hypertension'),
('Asthma'),
('Migraine'),
('Arthritis'),
('Pneumonia'),
('Bronchitis'),
('Gastroenteritis'),
('Depression');

INSERT INTO Medicines (Name, Company, Type, Prescribed_For) VALUES
('Ibuprofen', 'Pfizer', 'Painkiller', 1),
('Metformin', 'Merck', 'Oral Antidiabetic', 2),
('Lisinopril', 'Novartis', 'ACE Inhibitor', 3),
('Albuterol', 'GlaxoSmithKline', 'Bronchodilator', 4),
('Sumatriptan', 'AstraZeneca', 'Migraine Medication', 5),
('Prednisone', 'Teva', 'Corticosteroid', 6),
('Amoxicillin', 'Roche', 'Antibiotic', 7),
('Dextromethorphan', 'Johnson & Johnson', 'Cough Suppressant', 8),
('Ondansetron', 'Sanofi', 'Antiemetic', 9),
('Sertraline', 'Bayer', 'SSRI Antidepressant', 10);

INSERT INTO Departments (Name) VALUES
('Cardiology'),
('Neurology'),
('Orthopedics'),
('Pediatrics'),
('Gastroenterology'),
('Oncology'),
('Endocrinology'),
('Psychiatry'),
('Dermatology'),
('ENT');

INSERT INTO Doctors (Name, Specialization, Department_Id, Contact, Email, Shift) VALUES
('Dr. John Smith', 'Cardiologist', 1, '123-456-7890', 'johnsmith@example.com', 'Morning'),
('Dr. Emily Johnson', 'Neurologist', 2, '234-567-8901', 'emilyjohnson@example.com', 'Evening'),
('Dr. Michael Brown', 'Orthopedic Surgeon', 3, '345-678-9012', 'michaelbrown@example.com', 'Night'),
('Dr. Sarah Lee', 'Pediatrician', 4, '456-789-0123', 'sarahlee@example.com', 'Morning'),
('Dr. David Wang', 'Gastroenterologist', 5, '567-890-1234', 'davidwang@example.com', 'Evening'),
('Dr. Jennifer Garcia', 'Oncologist', 6, '678-901-2345', 'jennifergarcia@example.com', 'Night'),
('Dr. Robert Martinez', 'Endocrinologist', 7, '789-012-3456', 'robertmartinez@example.com', 'Morning'),
('Dr. Laura Rodriguez', 'Psychiatrist', 8, '890-123-4567', 'laurarodriguez@example.com', 'Evening'),
('Dr. Christopher Nguyen', 'Dermatologist', 9, '901-234-5678', 'christophernguyen@example.com', 'Night'),
('Dr. Samantha Kim', 'ENT Specialist', 10, '012-345-6789', 'samanthakim@example.com', 'Morning');

INSERT INTO Rooms (Room_No, Department_Id, Capacity) VALUES
('101', 1, 2),
('102', 2, 3),
('103', 3, 4),
('201', 4, 2),
('202', 5, 3),
('203', 6, 4),
('301', 7, 2),
('302', 8, 3),
('303', 9, 4),
('401', 10, 2);

INSERT INTO Patients (Name, DOB, Gender, Address, Contact, Room_Id, Disease_Id, Medicine_Id) VALUES
('Alice Johnson', '1985-03-15', 'Female', '123 Main St, Anytown', '555-123-4567', 1, 1, 1),
('Bob Smith', '1990-07-20', 'Male', '456 Elm St, Othertown', '555-234-5678', 2, 2, 2),
('Alice Johnson', '1985-03-15', 'Female', '123 Main St, Anytown', '555-123-4567', 3, 3, 3),
('Charlie Brown', '1982-11-10', 'Male', '789 Oak St, Anothertown', '555-345-6789', 4, 4, 4),
('David Lee', '1978-09-25', 'Male', '246 Pine St, Somewhere', '555-456-7890', 5, 5, 5),
('Eva Hernandez', '1995-04-30', 'Female', '369 Maple St, Nowhere', '555-567-8901', 6, 6, 6),
('Bob Smith', '1990-07-20', 'Male', '456 Elm St, Othertown', '555-234-5678', 7, 7, 7),
('Grace Taylor', '1989-12-05', 'Female', '135 Cedar St, Here', '555-678-9012', 8, 8, 8),
('Harry Brown', '1976-01-12', 'Male', '579 Birch St, There', '555-789-0123', 9, 9, 9),
('Isabel Kim', '1980-08-08', 'Female', '802 Walnut St, Everywhere', '555-890-1234', 10, 10, 10);

INSERT INTO Appointments (Patient_Id, Doctor_Id, Date_Time) VALUES
(1, 1, '2024-02-10 09:00:00'),
(2, 2, '2024-02-11 10:00:00'),
(3, 3, '2024-02-12 11:00:00'),
(4, 4, '2024-02-13 12:00:00'),
(5, 5, '2024-02-14 13:00:00'),
(6, 6, '2024-02-15 14:00:00'),
(7, 7, '2024-02-16 15:00:00'),
(8, 8, '2024-02-17 16:00:00'),
(9, 9, '2024-02-18 17:00:00'),
(10, 10, '2024-02-19 18:00:00');
