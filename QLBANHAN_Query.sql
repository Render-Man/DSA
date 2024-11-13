USE master
--CREATING DATABASE--
IF(EXISTS(SELECT * FROM SYS.DATABASES WHERE NAME='QLBANHANG'))
DROP DATABASE QLBANHANG
GO

CREATE DATABASE QLBANHANG
ON PRIMARY(
 NAME='QLBANHANG_dat',
 FILENAME='D:\HTCSDL\QLBANHANG.mdf',
 SIZE=10MB,
 MAXSIZE=50MB,
 FILEGROWTH=10MB
)

LOG ON
(
 NAME='QLBANHANG_log',
 FILENAME='D:\HTCSDL\QLBANHANG_LOG.ldf',
 SIZE=1MB,
 FILEGROWTH=100KB
)
GO

USE QLBANHANG
GO

--CREATING TABLES--

DROP TABLE HangSX

CREATE TABLE HangSX
(
	MaHangSX CHAR(10) NOT NULL PRIMARY KEY,
	TenHang NVARCHAR(50),
	DiaChi NVARCHAR(100),
	SoDT CHAR(12),
	Email VARCHAR(100)
)
--
DROP TABLE SanPham

CREATE TABLE SanPham
(
	MaSP CHAR(10) NOT NULL,
	MaHangSX CHAR(10) NOT NULL FOREIGN KEY(MaHangSX) REFERENCES HangSX(MaHangSX),
	TenSP NVARCHAR(50),
	SoLuong INT,
	MauSac NVARCHAR(20),
	GiaBan MONEY,
	DonViTinh NVARCHAR(20),
	MoTa NTEXT,
	CONSTRAINT MaSP PRIMARY KEY(MaSP)
)

DROP TABLE NhanVien

CREATE TABLE NhanVien
(
	MaNV CHAR(10) NOT NULL PRIMARY KEY,
	TenNV NVARCHAR(50),
	GioiTinh NCHAR(10),
	DiaChi NVARCHAR(100),
	SoDT CHAR(12),
	Email VARCHAR(50),
	TenPhong NVARCHAR(100)
	--CONSTRAINT MaNV PRIMARY KEY(MaNV)
)

DROP TABLE PNhap

CREATE TABLE PNhap
(
	SoHDN CHAR(10) NOT NULL PRIMARY KEY,
	NgayNhap DATE,
	MaNV CHAR(10) NOT NULL,
	CONSTRAINT MaNV FOREIGN KEY(MaNV) REFERENCES NhanVien(MaNV)
)

DROP TABLE Nhap

CREATE TABLE Nhap
(
	SoHDN CHAR(10) NOT NULL,
	MaSP CHAR(10) NOT NULL,
	SoLuongN Int,
	DonGiaN MONEY,
	PRIMARY KEY(SoHDN, MaSP),
	FOREIGN KEY(SoHDN) REFERENCES PNhap(SoHDN),
	FOREIGN KEY(MaSP) REFERENCES SanPham(MaSP)
)

DROP TABLE PXuat

CREATE TABLE PXuat
(
	SoHDX CHAR(10) PRIMARY KEY NOT NULL,
	NgayXuat DATE,
	MaNV CHAR(10) FOREIGN KEY(MaNV) REFERENCES NhanVien(MaNV),
)

DROP TABLE Xuat

CREATE TABLE Xuat
(
	SoHDX CHAR(10) NOT NULL,
	MaSP CHAR(10) NOT NULL,
	SoLuongXuatX INT,
	PRIMARY KEY(SoHDX, MaSP),
	FOREIGN KEY(SoHDX) REFERENCES PXuat(SoHDX),
	FOREIGN KEY(MaSP) REFERENCES SanPham(MaSP)
)

--INSERTING DATAS

--HANG SAN XUAT
INSERT HangSX(MaHangSX, TenHang, DiaChi, SoDT, Email) 
VALUES
('H01', 'SamSung', 'Korea', '011-0827717', 'ss@gmail.com.kr'),
('H02', 'OPPA', 'China', '081-08626261', 'oppo@gmail.com.cn'),
('H03', 'Vinfone', N'Việt Nam', '084-09826262', 'vf@gmail.com.vn')


--NHAN VIEN
INSERT INTO NhanVien (MaNV, TenNV, GioiTinh, DiaChi, SoDT, Email, TenPhong) 
VALUES
('NV01', N'Nguyễn Thị Thu', N'Nữ', N'Hà Nội', '0982626521', 'thu@gmail.com', N'Kế toán'),
('NV02', N'Lê Văn Nam', N'Nam', N'Bắc Ninh', '0972525252', 'nam@gmail.com', N'Vật tư'),
('NV03', N'Trần Hòa Bình', N'Nữ', N'Hà Tây', '0328388388', 'hb@gmail.com', N'Kế toán')



--SAN PHAM
INSERT INTO SanPham (MaSP, MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa) 
VALUES
('SP01', 'H02', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
('SP02', 'H01', 'Galaxy Note 11', 50, N'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
('SP03', 'H02', 'F3 lite', 200, N'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
('SP04', 'H03', 'Vjoy3', 200, N'Xám', 15000000, N'Chiếc', N'Hàng phổ thông'),
('SP05', 'H01', 'Galaxy V21', 500, N'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp')


--PHIEU NHAP
INSERT INTO PNhap(SoHDN, NgayNhap, MaNV)
VALUES
('N01', '02-05-2019', 'NV01'),
('N02', '04-07-2020', 'NV02'),
('N03', '05-17-2020', 'NV02'),
('N04', '03-22-2020', 'NV03'),
('N05', '07-07-2020', 'NV01')



-- NHAP
INSERT INTO Nhap(SoHDN, MaSP, SoLuongN, DonGiaN)
VALUES
('N01', 'SP02', 10, 17000000),
('N02', 'SP01', 30, 60000000),
('N03', 'SP04', 20, 120000000),
('N04', 'SP01', 10, 62000000),
('N05', 'SP05', 20, 70000000)

SELECT * FROM Nhap

-- PHIEU XUAT
INSERT INTO PXuat(SoHDX, NgayXuat, MaNV)
VALUES
('X01', '06-14-2020', 'NV02'),
('X02', '03-05-2019', 'NV03'),
('X03', '06-14-2020', 'NV01'),
('X04', '06-02-2020', 'NV02'),
('X05', '05-18-2020', 'NV01')

SELECT * FROM PXuat

-- XUAT
INSERT INTO Xuat(SoHDX, MaSP, SoLuongXuatX)
VALUES
('X01', 'SP03', 5),
('X02', 'SP01', 3),
('X03', 'SP02', 1),
('X04', 'SP03', 2),
('X05', 'SP05', 1)

SELECT * FROM Xuat

--UPDATING DATAS
--e. Cập nhật lại Địa chỉ Nhân viên Hà tây thành Hà nội

UPDATE NhanVien
SET DiaChi=N'Hà Nội'
WHERE DiaChi=N'Hà Tây'

SELECT * FROM NhanVien

--REMOVING DATAS
DELETE FROM HangSX

DELETE FROM SanPham
WHERE MaHangSX='H01'

SELECT * FROM SanPham


SELECT * FROM HangSX
SELECT * FROM SanPham
SELECT * FROM NhanVien
SELECT * FROM PNhap
SELECT * FROM PXuat
SELECT * FROM Nhap
SELECT * FROM Xuat

