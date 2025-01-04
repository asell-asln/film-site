#include <stdio.h>
#include <string.h>

// Üyelik ücretleri ve açıklamaları
int odeme[5] = {100, 125, 90, 170, 150};
char *plan_aciklama[5] = {
    "STANDART UYELIK: Yerli, yabanc, komedi, korku, ask, animasyon, cizgi film ve bilim kurgu icerikleri.",
    "MAC UYELIK: Yerli ve yabanci tum mac icerikleri.",
    "OGRENCI MAC UYELIK: Yerli ve yabanci tum mac iceriklerine indirimli fiyatla erisim.",
    "DUO UYELIK: Iki kisilik hesapla genis bir icerik yelpazesi.",
    "OGRENCI DUO UYELIK: Iki kisilik hesapla indirimli icerikler."
};

// Kullanıcı bilgilerini al
void kullanici_bilgisi_al(char ad[], char soyad[], char eposta[], int *yas) {
    printf("ADINIZ: ");
    scanf("%s", ad);

    printf("SOYADINIZ: ");
    scanf("%s", soyad);

    printf("EPOSTANIZ: ");
    scanf("%s", eposta);

    printf("YASINIZ: ");
    scanf("%d", yas);
}

// Üyelik planlarını listele
void planlari_listele() {
    printf("\n-- Lutfen plan ismi seciniz --\n\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. uyelik --> %s (Ucret: %d TL)\n", i + 1, plan_aciklama[i], odeme[i]);
    }
}

// Kullanıcıdan üyelik planı seçmesini iste
int plan_sec() {
    int plan;
    printf("Seciminiz (1-5): ");
    scanf("%d", &plan);

    if (plan < 1 || plan > 5) {
        printf("\nHatalı bir secim yaptiniz. Lutfen tekrar deneyiniz.\n");
        return -1;
    }
    return plan;
}

// Ödeme işlemini gerçekleştir
int odeme_yap() {
    int onay;
    printf("Odeme yapmak icin 1 yaziniz: ");
    scanf("%d", &onay);

    if (onay == 1) {
        printf("\nOdemeniz basarili! Uyeliginiz tamamlanmistir.\n");
        return 1;
    } else {
        printf("\nOdeme yapilamadi. Uyelik tamamlanamadi.\n");
        return 0;
    }
}

int main() {
    char ad[50], soyad[50], eposta[100];
    int yas;

    printf("^^ FILM SITESI ^^ \n\n");

    // Kullanıcı bilgilerini al
    kullanici_bilgisi_al(ad, soyad, eposta, &yas);

    // Yaşa göre kontrol yap
    if (yas < 18) {
        printf("\nSite kisitli içerikle beraber ucretsizdir.\n");
        return 0;
    } else {
        printf("\nSite sinirsiz içerikle beraber ucretlidir.\n");
        printf("Oğrenci oldugunuzu aktive etmek için belgenizi aşagıdaki alana yukleyiniz.\n\n");
        printf("-------------------------------------\n\n");
    }

    // Planları listele ve seçim yap
    planlari_listele();
    int plan = plan_sec();

    // Plan seçimi doğru ise ödeme al
    if (plan != -1) {
        printf("\n%s\n", plan_aciklama[plan - 1]);
        printf("Secilen plan ucreti: %d TL\n", odeme[plan - 1]);
        odeme_yap();
    }

    return 0;
}