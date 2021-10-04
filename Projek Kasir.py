"""
Muhammad Yazid Baihaqi
    0102520037
    Informatika
"""
import os
os.system('cls')
nama= input("Nama (max 8 karakter) : ")
def meja():
    global lis, pil_meja, meja_anda
    lis = [
        "Meja 1 ( 1  orang)","Meja 2 ( 2  orang)","Meja 3 (3-4 orang)", 
        "Meja 4 (5-6 orang)", "Meja 5 ( >6 orang)"
    ]
    n = 0
    print("""\n=========================================
\t\t DAFTAR MEJA\t\t
=========================================\n""")
    for a in (lis):
        n=n+1
        print("\t%d. %s\t\n" %(n,a))
    pil_meja = int(input(("Pilih Meja: ")))
    meja_anda = lis[pil_meja-1].upper()
    print("\n>>> SILAHKAN PERGI KE %s <<<" %meja_anda)
    print("\n\n\n")
    os.system('pause')
    os.system('cls')

 #-------Call Function choose Meja------------
def daftar_menu():
    global sedia
    sedia = [ ["Air Mineral", 0], ["Nasi putih", 0],
            ["Ayam Bakar", 10.000], ["Ayam Goreng", 8.000], ["Soto Ayam", 15.000],
            ["Soto Babat", 15.000], ["Sate Ayam", 25.000],  ["Sate Kambing", 30.000],
            ["Nasi Goreng", 15.000],["Nasi Kucing", 20.000],["Nasi Kebuli", 15.000],
            ["Nasi Kuning", 15.000],["Jus Alpukat", 5.000], ["Jus Apel", 5.000],
            ["Jus Lemon", 5.000],   ["Jus Mangga", 5.000],  [" Teh  Panas", 2.000],
            [" Teh  Dingin", 2.000]]
    n = 0
    print("""\n=========================================
\t\t DAFTAR MENU\t
=========================================\n""")
    for b in sedia:
        n = n+1
        print("\t%d. %s (Rp %.3f)\n" %(n,b[0],b[1]))

def Proses():
    x = 0
    global list_semua 
    list_semua = [[] for k in range (3)]

    while True:

        global pil_menu
        x=x+1
        print("\n=========================================")
        print("\t\tMenu ke-%d " %x)
        print("=========================================")
        #---------------No menu yang dipesan------------------
        pil_menu = int(input(("\n\tNo. Menu: ")))
        if pil_menu < 1 or pil_menu > len(sedia): 
            print("\n\tMAAF, MENU TIDAK ADA")
            os.system('cls')
            daftar_menu()
            Proses()
            Transaksi()
        i = sedia[pil_menu-1][0]
        j = sedia[pil_menu-1][1]
        list_semua[0].append(i)
        print("\tNo (%d) %s Rp %.3f" %(pil_menu,i,j))

        #--------------Banyak Menu & Harga Menu---------------
        banyak_menu = int(input(("\n\tJumlah Pesanan: ")))
        jumlah_menu = j*banyak_menu
        print("\t*** %d %s Rp %.3f ***" %(banyak_menu, i, jumlah_menu))
    
        list_semua[1].append(banyak_menu)
        list_semua[2].append(jumlah_menu)

        #--------------Menanyakan user------------------------
        pesan_lagi = input("\nPesan lagi?[Y/T]: ")
        if pesan_lagi == "T" or pesan_lagi == "t":
            break

def Transaksi():
    print("""\n
=========================================
|             STRUK PEMBELIAN           |
=========================================
|\t%s > %s\t|
=========================================""" %(nama,meja_anda))
    for it in range(len(list_semua[0])):
        print("|\t %d %s Rp %.3f  \t| " %(list_semua[1][it], list_semua[0][it].upper(), list_semua[2][it]))
    print("=========================================")
    total = 0   
    for item in list_semua[2]: total += item
    pajak = 1/100 * total
    total += pajak
    
    print("""|             PAJAK Rp %.3f            |
=========================================  
|\t*** TOTAL Rp %.3f ***  \t|
=========================================""" %(pajak,total)) 

    bayar = float(input("\nBAYAR\t: Rp "))
    if bayar < total:
        print("\n\t MAAF SALDO ANDA TIDAK MENCUKUPI\n\tTekan 'ENTER' Untuk membayar Kembali\n\n\n")
        os.system('Pause') 
        os.system('cls') 
        Transaksi() 
        exit()
    bayar -= total
    print("SISA\t: Rp %.3f" %(float(bayar)))
    print("""
    \tTERIMAKASIH SUDAH BERKUNJUNG \n\n\n""")
    os.system("pause")

meja()
daftar_menu()
Proses()
Transaksi()
