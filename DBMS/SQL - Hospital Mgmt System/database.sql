CREATE DATABASE HospitalDb;

USE HospitalDb;

-- Diseases Table
CREATE TABLE Diseases (
    Disease_Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL
);

-- Medicines Table
CREATE TABLE Medicines (
    Medicine_Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    Company VARCHAR(100),
    Type VARCHAR(20),
    Prescribed_For INT NOT NULL,
    FOREIGN KEY (Prescribed_For) REFERENCES Diseases(Disease_Id)
);

-- Department Table
CREATE TABLE Departments (
    Department_Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL
);

-- Doctor Table
CREATE TABLE Doctors (
    Doctor_Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    Specialization VARCHAR(100) NOT NULL,
    Department_Id INT NOT NULL,
    Contact VARCHAR(15),
    Email VARCHAR(100),
    Shift VARCHAR(10),
    FOREIGN KEY (Department_Id) REFERENCES Departments(Department_Id)
);

-- Rooms Table
CREATE TABLE Rooms (
    Room_Id INT PRIMARY KEY IDENTITY(1,1),
    Room_No VARCHAR(10) NOT NULL,
    Department_Id INT NOT NULL,
    Capacity INT,
    FOREIGN KEY (Department_Id) REFERENCES Departments(Department_Id)
);

-- Patients Table
CREATE TABLE Patients (
    Patient_Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    DOB DATE NOT NULL,
    Gender CHAR(10) NOT NULL,
    Address VARCHAR(100),
    Age AS DATEDIFF(YEAR, DOB, GETDATE()),
    Contact VARCHAR(15),
    Room_Id INT NOT NULL,
    Disease_Id INT NOT NULL,
    Medicine_Id INT NOT NULL,
    FOREIGN KEY (Room_Id) REFERENCES Rooms(Room_Id),
    FOREIGN KEY (Disease_Id) REFERENCES Diseases(Disease_Id),
    FOREIGN KEY (Medicine_Id) REFERENCES Medicines(Medicine_Id)
);

-- Appointments Table
CREATE TABLE Appointments (
    Appointment_Id INT PRIMARY KEY IDENTITY(1,1),
    Patient_Id INT NOT NULL,
    Doctor_Id INT NOT NULL,
    Date_Time DATETIME NOT NULL,
    FOREIGN KEY (Patient_Id) REFERENCES Patients(Patient_Id),
    FOREIGN KEY (Doctor_Id) REFERENCES Doctors(Doctor_Id)
);
