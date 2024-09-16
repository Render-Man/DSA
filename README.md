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