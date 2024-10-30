# DSA

Cách dùng git

## Cách 1: Via Upload

Add files > Upload files

<image src="github-tutorial/uploadviaweb.png"></image>

## Cách 2: Dùng App/Software

Ví dụ dùng VSCode:

<image src="github-tutorial/vscode_git01.png"></image>

Trong tab source control, chỉ cần bấm dấu + vào các file muốn thay đổi, gõ message rồi bấm commit, sau đó push là ok


## Cách 3: Dùng command prompt

### 1) mở command prompt

### 2) cd [path] để đi tới thư mục muốn đặt repository vào

ví dụ 

```
cd C:\Projects
```

### 3) Git clone

clone repository trên github về máy

```
git clone https://github.com/Render-Man/DSA.git
```

sau khi clone, git sẽ tự động tải repository về máy

### 4) Code...

Sau khi có local repo trong máy, nếu muốn code hoặc thay đổi thì mở ra và thay đổi

### 5) Đẩy code lên git

add files vào thay đổi:

```
git add . 
```

_git add ._ sẽ thêm tất cả các thay đổi, nếu muốn chỉ định cụ thể thì làm như sau, ví dụ chỉ muốn commit file ```sample.cpp``` trong thư mục ABC lên git

```
git add /ABC/sample.cpp
```

ví dụ tạo commit với message là: "update"
```
git commit -m"update"
```

sau đó, đẩy lên origin/main

```
git push origin main
```

## Nếu không push được là do có sự thay đổi từ remote, điều này xảy ra vì khi làm team, mỗi bên lại code 1 đoạn khác nhau trong local(cụ thể là project trong máy cá nhân). Giả sử A push code lên, thì code trên github so với code trong máy của B là khác nhau. Để đồng bộ nó ta dùng git fetch.

git fetch sẽ tải về các thay đổi từ remote repository.

Dùng git fetch để tải các thay đổi, sau đó merge vào

```
git fetch
```

```
git merge
```

<image src="github-tutorial/fetchmerge.png"></image>

Trong ảnh là fetch về sau đó merge vào. Màu xanh cho thấy merge success, tức là ko có conflig(xung đột code - vấn đề nan giải khi mỗi thằng code 1 kiểu mà lại code chung files)

Sau đó thì add rồi push như thường

<image src="github-tutorial/pushdone.png"></image>

_(git status để xem status của git)_


--HANG SAN XUAT
INSERT HangSX(MaHangSX, TenHang, DiaChi, SoDT, Email) 
VALUES
('H01', 'SamSung', 'Korea', '011-0827717', 'ss@gmail.com.kr'),
('H02', 'OPPA', 'China', '081-08626261', 'oppo@gmail.com.cn'),
('H03', 'Vinfone', 'Việt Nam', '084-09826262', 'vf@gmail.com.vn')

SELECT * FROM HangSX

--NHAN VIEN
INSERT INTO NhanVien (MaNV, TenNV, GioiTinh, DiaChi, SoDT, Email, TenPhong) 
VALUES
('NV01', 'Nguyễn Thị Thu', 'Nữ', 'Hà Nội', '0982626521', 'thu@gmail.com', 'Kế toán'),
('NV02', 'Lê Văn Nam', 'Nam', 'Bắc Ninh', '0972525252', 'nam@gmail.com', 'Vật tư'),
('NV03', 'Trần Hòa Bình', 'Nữ', 'Hà Tây', '0328388388', 'hb@gmail.com', 'Kế toán')

SELECT * FROM NhanVien

--SAN PHAM
INSERT INTO SanPham (MaSp, MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa) 
VALUES
('SP01', 'H02', 'F1 Plus', 100, 'Xám', 7000000, 'Chiếc', 'Hàng cận cao cấp'),
('SP02', 'H01', 'Galaxy Note 11', 50, 'Đỏ', 19000000, 'Chiếc', 'Hàng cao cấp'),
('SP03', 'H02', 'F3 lite', 200, 'Nâu', 3000000, 'Chiếc', 'Hàng phổ thông'),
('SP04', 'H03', 'Vjoy3', 200, 'Xám', 15000000, 'Chiếc', 'Hàng phổ thông'),
('SP05', 'H01', 'Galaxy V21', 500, 'Nâu', 8000000, 'Chiếc', 'Hàng cận cao cấp')

SELECT * FROM SanPham

--PHIEU NHAP
INSERT INTO PNhap(SoHDN, NgayNhap, MaNV)
VALUES
('N01', '02-05-2019', 'NV01'),
('N02', '04-07-2020', 'NV02'),
('N03', '05-17-2020', 'NV02'),
('N04', '03-22-2020', 'NV03'),
('N05', '07-07-2020', 'NV01')

SELECT * FROM PNhap


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
SET DiaChi='Hà Nội'
WHERE DiaChi='Hà Tây'

SELECT * FROM NhanVien

--REMOVING DATAS

DELETE FROM SanPham
WHERE MaSP='SP01'

SELECT * FROM SanPham
