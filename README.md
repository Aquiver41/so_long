# so_long

`so_long`, 42 Network'ün grafik projelerinden biridir. Amaç; `.ber` formatında tanımlanan haritayı okuyup miniLibX ile bir pencere açmak, oyuncuyu hareket ettirmek, tüm toplanabilirleri (`C`) aldıktan sonra çıkışa (`E`) ulaştırmaktır. Bu repo şu an harita okuma/validasyon, kaynak kütüphanelerinin entegrasyonu ve pencere yönetimi üzerinde yoğunlaşmış bir başlangıç noktası sağlar.

## Gereksinimler

- GCC veya Clang gibi bir C derleyicisi
- GNU Make
- X11 başlıkları ve kütüphaneleri (Ubuntu/Debian için örnek: `sudo apt install make gcc xorg libxext-dev libbsd-dev`)
- miniLibX, `libft` ve `ft_printf` projeleri bu repo içinde **submodule değil**, doğrudan dizin olarak bulunuyor. Ek kurulum yapmanız gerekmiyor.

## Derleme

```bash
make
```

Komut, önce `libft`, `ft_printf` ve `minilibx-linux` dizinlerini derler, ardından `src/` altındaki dosyaları derleyip `so_long` çalıştırılabilirini üretir. Yardımcı hedefler:

- `make clean` → obje dosyalarını temizler.
- `make fclean` → obje dosyaları + `so_long` ikilisini temizler (alt projelerdeki hedefler de silinir).
- `make re` → tam yeniden derleme.

## Çalıştırma

```bash
./so_long maps/map1.ber
```

- Program yalnızca **bir** argüman bekler: `.ber` uzantılı harita dosyası.
- Hatalı argüman sayısı veya dosya yolu için kullanıcıya okunabilir hata mesajı verir.
- Varsayılan pencere boyutu şu an 1920×1080 olarak ayarlanmış durumda ve pencereyi `Esc` tuşu ya da pencereyi kapatarak sonlandırabilirsiniz.

## Harita Formatı

Kaynak: `src/check_in.c` ve `src/init.c`

- Dosya uzantısı `.ber` olmalıdır.
- Harita dikdörtgen olmalı ve satır sonundaki newline karakterlerine dikkat edilmelidir; arada boş satır bulunamaz.
- Tüm harita, dış sınırlar dahil olmak üzere `1` karakteriyle çevrelenmelidir.
- Geçerli karakterler: `0` (zemin), `1` (duvar), `C` (collectible), `E` (exit), `P` (oyuncu başlangıç noktası).
- `P` ve `E` tam olarak birer tane olmalıdır.
- En az bir adet `C` olmalıdır; aksi durumda oyun mantığının çalışması mümkün olmayacak şekilde hata verir.

Örnek bir harita dosyası `maps/map1.ber` içinde yer alır.

## Kod Düzeni

| Yol            | Açıklama |
|----------------|----------|
| `src/`         | Ana oyun döngüsü, harita yükleme, hata mesajları ve kontroller. |
| `libft/`       | 42 `libft` uygulamanız; string/memory yardımcıları burada. |
| `ft_printf/`   | Biçimlendirilmiş çıktı için özelleştirilmiş `printf`. |
| `minilibx-linux/` | miniLibX kütüphanesi (Linux sürümü). |
| `maps/`        | Örnek `.ber` haritaları. |
| `img/`         | Oyunun görsellerini yerleştirmeniz için ayrılmış dizin. |

Henüz `draw_map.c`, `images.c` ve `hooks.c` dosyaları boş olduğundan; oyuncu hareketleri, sprite çizimleri ve koleksiyon mantığı tamamlanmayı bekliyor. Mevcut haliyle uygulama yalnızca haritayı okuyup pencereyi açıyor; geri kalan oyun kurallarını siz tamamlamalısınız.

## Yol Haritası / Yapılacaklar

1. `draw_map.c` içinde harita temsilini tile'lara dönüştürüp miniLibX ile ekrana çizmek.
2. `hooks.c` üzerinde `WASD`/ok tuşu girişlerini işleyip oyuncuyu hareket ettirmek.
3. Collectible sayacı tutup tüm `C`ler toplanmadan `E`'yi pasif tutmak.
4. `images.c` dosyasında sprite yüklemelerini, boyut ölçeklemelerini ve hata kontrolünü tamamlamak.
5. Ekstra bonuslar: hareket sayacı göstergesi, farklı düşman tipleri, pencere boyutunu harita ile ilişkilendirmek.

Katkıda bulunmak veya incelemek isteyenler için bu README, projeyi hızlıca ayağa kaldırmanıza ve geliştirmenize yardımcı olmayı amaçlıyor. İyi çalışmalar!
