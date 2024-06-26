﻿# Triatlon-Case-Study

Triatlon; yüzme, bisiklet ve koşu olmak üzere üç farklı spordan oluşan bir yarışmadır (5 km yüzme, 40 km bisiklet ve 10 km koşu). Bu projede, triatlon yarışmasının bir simülasyonu gerçekleştirilmiştir. Proje, her bir sporcunun hızını ve konumunu hesaplayarak, parkurlar arasındaki geçişleri ve yarış sonucunu belirler. Aynı zamanda en iyi dereceyi yapan sporcuya ve takıma ödül verir.

## Özellikler

- Sporcular parkur geçişlerinde 10 saniye zaman kaybetmektedir.
- Her bir sporcunun anlık konumu ve hızı bulunmaktadır. Hızlar birinci parkurun başlangıcında (minimum 1 metre/saniye, maksimum 5 metre/saniye) rastgele alınır.
- Sporcuların konumları, ekran kartında farklı thread’ler tarafından paralel olarak hesaplanır.
- İkinci parkura gelindiğinde sporcuların hızları 3 katına çıkar.
- Üçüncü parkurda ise sporcuların hızları, ilk parkurdaki hızlarının 1/3’üne iner.
- Ekran kartı saniyede bir kere çalıştırılır ve her bir çalıştırmada tüm sporcuların yeni anlık konumu hesaplanır.
- Hangi takımın hangi sporcusunun, hız ve konum bilgisi kullanıcıdan input olarak alınabilir ve çıktı olarak verilir.
- İlk sporcu bitiş çizgisine ulaştığında, tüm sporcuların o an bulundukları konumlar yazdırılır.
- Tüm sporcular yarışı bitirdiğinde yarışın takım sıralaması ekrana yazdırılır.


### Derleme

Proje kök dizininde şu komutu çalıştırarak projeyi derleyin:

```bash
g++ -I./triatlon/include ./triatlon/src/*.cpp -o main
```
Derleme tamamlandıktan sonra şu komutla programı çalıştırın:

```bash
./main
```

### Gerekli Kütüphaneler
Projede threading ve zaman fonksiyonları kullanıldığı için -pthread bayrağını kullanarak derleme yapabilirsiniz:

```bash
g++ -pthread -I./triatlon/include ./triatlon/src/*.cpp -o main
```
