# Kalkulator Ekspresi

Program kalkulator berbasis **C++** yang dapat menghitung ekspresi **infix**, **prefix**, dan **postfix** menggunakan implementasi **stack**.  
Dibuat sebagai latihan untuk memahami konsep struktur data stack dan konversi notasi matematika.

## 🎯 Fitur
- Menghitung ekspresi infix, prefix, dan postfix  
- Konversi antar bentuk ekspresi  
- Implementasi stack manual tanpa library STL  
- Antarmuka berbasis terminal (CLI)

## 📂 Struktur Folder
```
├── main.cpp              # Program utama
├── stack.h               # Header untuk deklarasi stack
├── stack.cpp             # Implementasi fungsi stack
├── KalkulatorEkspresi.cbp # File proyek Code::Blocks
└── bin/ & obj/           # Folder hasil build (otomatis)
```

## ⚙️ Cara Menjalankan
1. Clone repository:
   ```bash
   git clone https://github.com/AhidNovrya/kalkulatorEkspresi.git
   ```
2. Buka proyek dengan **Code::Blocks** atau IDE C++ lain.
3. Jalankan (`Build and Run`) program.
4. Masukkan ekspresi sesuai format yang diminta oleh program.

## 🧮 Contoh Penggunaan
```
Masukkan ekspresi: (3 + 4) * 2
Hasil (infix): 14
Hasil (prefix): * + 3 4 2
Hasil (postfix): 3 4 + 2 *
```

## 📘 Konsep yang Digunakan
- Struktur data **Stack**
- Algoritma **Infix to Postfix/Prefix Conversion**
- Evaluasi ekspresi aritmatika

## 🧩 Diagram Alur Konversi Ekspresi
```
           +-----------------------+
           |   Masukkan Ekspresi   |
           +----------+------------+
                      |
                      v
          +-----------+------------+
          |  Baca tiap karakter    |
          +-----------+------------+
                      |
        +-------------+-------------+
        | Karakter operand?         |
        | (angka / huruf)           |
        +-------------+-------------+
                      |
        +-------------v-------------+
        | Tambahkan ke output        |
        +-------------+-------------+
                      |
        | Operator? ( + - * / ^ )   |
        +-------------+-------------+
                      |
        +-------------v-------------+
        | Bandingkan prioritas dan  |
        | push/pop stack sesuai aturan |
        +-------------+-------------+
                      |
        +-------------v-------------+
        | Jika tanda kurung,         |
        | atur sesuai aturan ( )     |
        +-------------+-------------+
                      |
                      v
           +----------+------------+
           |   Hasil ekspresi baru |
           +-----------------------+
```

## 🧑‍💻 Pengembang
**Ahid Novrya**  
Mahasiswa S1 Teknologi Informasi  
[GitHub: @AhidNovrya](https://github.com/AhidNovrya)

---

Lisensi: **MIT License**
