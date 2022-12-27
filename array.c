// Kişilik tiplerindeki harfleri tutar yan yana olan her harf birbirinin zıttıdır
char categories[6][2] = {
    {'E', 'I'},
    {'N', 'S'},
    {'T', 'F'},
    {'J', 'P'},
    {'-', '-'},
    {'A', 'T'},
};

// Her bir soruya ne kadar katıldığımıza göre veren puanları tutar
int scores[20][5] = {
    {-4, -2, 0, 2, 4},
    {-8, -4, 0, 4, 8},
    {-4, -2, 0, 2, 4},
    {4, 2, 0, -2, -4},
    {-6, -3, 0, 3, 6},

    {-8, -4, 0, 4, 8},
    {-4, -2, 0, 2, 4},
    {6, 3, 0, -3, 6},
    {-10, -5, 0, 5, 10},
    {-6, -3, 0, 3, 6},

    {-8, -4, 0, 4, 8},
    {4, 2, 0, -2, -4},
    {-10, -5, 0, 5, 10},
    {-10, -5, 0, 5, 10},
    {-8, -4, 0, 4, 8},

    {-10, -5, 0, 5, 10},
    {-8, -4, 0, 4, 8},
    {4, 2, 0, -2, -4},
    {-6, -3, 0, 3, 6},
    {-6, -3, 0, 3, 6},
};

// Her bir kategorinin toplam puanını tutar sorular ile bu puanlar azalıp artar ve bir tipe yaklaşır
int categoriesScores[5] = {50, 50, 50, 50, 10};

// Kişilik tiplerini tutar
char type[16][5] = {
    {"INTJ\0"},
    {"INTP\0"},
    {"ENTJ\0"},
    {"ENTP\0"},
    {"INFJ\0"},
    {"INFP\0"},
    {"ENFJ\0"},
    {"ENFP\0"},
    {"ISTJ\0"},
    {"ISFJ\0"},
    {"ESTJ\0"},
    {"ESFJ\0"},
    {"ISTP\0"},
    {"ISFP\0"},
    {"ESTP\0"},
    {"ESFP\0"},
};

// Test sonucunda çıkan kişiliğe özel açıklama yapar
char typeDescription[16][500] = {
    {"Her şey için bir planı olan hayalperest ve stratejik düşünenler.\n\nÖrnek: Elon Musk - Walter White - Gandalf\0"},
    {"Bilgi için bastırılamaz bir susuzluğu olan yenilikçi mucitler.\n\nÖrnek: Bill Gates - Albert Einstain - Neo\0"},
    {"Her zaman bir yolunu bulan ya da bir yol yaratan cesur, hayalperest ve dirayetli liderler.\n\nÖrnek:  Steve Jobs - Doctor Strange - Franklin D. Roosevelt\0"},
    {"Entelektüel zorluklara direnemeyen akıllı ve meraklı düşünürler.\n\nÖrnek: Thomas Edison - Captain Jack Sparrow - Joker\0"},
    {"Sessiz ve mistik fakat halen ilhan verici ve yılmaz idealistler.\n\nÖrnek: Goethe - Martin Luther King - Aragorn\0"},
    {"İyi bir davaya yardım etmeye her zaman hazır Şiirsel, kibar ve fedakâr insanlar.\n\nÖrnek: Jhonny Depp - Tom Hiddleston - William Shakespeare\0"},
    {"Dinleyicilerini büyüleme yeteneği olan karizmatik ve ilham verici liderler.\n\nÖrnek: Barack Obama - Morpheus - Ben Affleck\0"},
    {"Gülmek için her zaman bir sebep bulabilen coşkulu, yaratıcı ve sosyal özgür ruhlar.\n\nÖrnek: Will Smith - Spider-Man - Willy Wonka\0"},
    {"Güvenirliklerinden kuşku edilemez pratik ve hakikat merkezli bireyler.\n\nÖrnek: George Washington - Hermione Granger - Geralt of Rivia\0"},
    {"Sevdiklerini savunmaya her zaman hazır kendini cidden adamış ve sıcakkanlı korunmacılar.\n\nÖrnek: Queen Elizabeth - Captain America - Vito Corleone\0"},
    {"Bir şeyleri veya insanları idare etmek konusunda emsalsiz olan mükemmel yöneticiler.\n\nÖrnek: John D. Rockefeller - Judge Judy - Ella Baker\0"},
    {"Her zaman yardıma hazır olağanüstü alakadar, sosyal ve popüler insanlar.\n\nÖrnek: Taylor Swift - Jennifer Lopez - Steve Harvey\0"},
    {"Her türlü alette usta cesur ve pratik denemeciler.\n\nÖrnek: Bear Grylls - Michaek Jordon - Indiana Jones\0"},
    {"Yeni bir şeyi araştırmaya ve deneyim etmeye hazır rahat ve büyüleyici sanatçılar.\n\nÖrnek: Frida Kahlo - Michael Jackson - Beatrix Kiddo\0"},
    {"Uçlarda yaşamaktan gerçekten zevk alan zeki, enerjik ve perspektif sahibi insanlar.\n\nÖrnek: Rocket - Ant-Man - Madonnda\0"},
    {"Etraflarında hayatın hiçbir sıkıcı olmayan spontane, enerjik ve coşkulu eğlendiriciler.\n\nÖrnek: Marilyn Monroe - Captain Marvel - Jack Dawson\0"},
};