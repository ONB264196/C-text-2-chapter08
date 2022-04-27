#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#define _0807

#define QNO 12
#define swap(type, x, y)	do{ type t = x; x = y; y = t;} while (0)
#define NO 10
#define KTYPE 16
#define POS_LEN 10


enum class Menu{ Term, KeyPos, KeyPosComp, Clang, Conversation, Suggestion, HomePos2, HomePos3, InValid } ;
const char* kstr[] = { "12345", "67890-^\\",
						"!\"#$%", "&'()=~|",
						"qwert", "yuiop@[]",
						"QWERT", "YUIOP`{}",
						"asdfg", "hjkl;:",
						"ASDFG", "HJKL+*",
						"zxcvb", "nm,./\\",
						"ZXCVB", "NM<> _"
};
const char* cstr[] = { "auto","break","case","char","const","continue",
						"default","do","double","else","enum","extern",
						"float","for","goto","if","int","long",
						"register","return","short","signed","sizeof","static",
						"struct","switch","typedef","union","unsigned","void",
						"volatile","while",
						"abort","abs","acos","asctime","asin","assert",
						"atan","atan2","atexit","atof","atoi","atol",
						"bsearch","calloc","ceil","clearerr","clock","cos",
						"cosh","ctime","defftime","div","exit","exp",
						"fabs","fclose","feof","ferror","fflush","fgetc",
						"fgetpos","fgets","floor","fmod","fopen","fprintf",
						"fputc","fputs","fread","free","freopen","frexp",
						"fscanf","fseek","fsetpos","ftell","fwrite","getc",
						"getchar","getenv","gets","gmtime","isalpha",
						"iscntrl","isdigit","isgraph","islower","isprint","ispunct",
						"isspace","isupper","isxdigit","labs","ldexp","ldiv",
						"localconv","localtime","log","log10","longjmp",
						"malloc","memchr","memcmp","memcpy","memmove","memset",
						"mktime","modf","perror","pow","printf","putc",
						"putchar","puts","qsort","raise","rand","realloc",
						"remove","rename","rewind","scanf","setbuf","setjmp",
						"setlocal","setvbuf","signal","sin","sinh","sprintf",
						"sqrt","srand","sscanf","strcat","strchr","strcmp",
						"strcoll","strcpy","strcspn","strerror","strftime","strlen",
						"strncat","strncmp","strncpy","strpbrk","strrchr","strspn",
						"strstr","strtod","strtok","strtol","strtoul","strxfrm",
						"system","tan","tanh","time","tmpfile","tmpnam",
						"tolower","toupper","ungetc","va_arg","va_end","va_start",
						"vfprintf","vprintf","vsprintf" };
const char* vstr[] = { "Hellow!","How are you?","Fine thanks.",
						"I can't complain, thanks.","How do you do?","Good bye!",
						"Good morning!","Good afternoon!","Good evening!",
						"See you later!","Go ahead, please.","Thank you.",
						"No, thank you.","May I have your name?","I'm glad to meet you.",
						"What time is it now?","It's about seven.","I must go now.",
						"How much?","Where is the restroom?","Excuse me.",
						"Excuse us.","I'm sorry.","I don't know.",
						"I have no change with me.","I will be back.","Are you going out?",
						"I hope I'm not disturbing you.","I'll offer no excuse.","Shall we dance?",
						"Will you do me a favor?","It's very unseasonable.","You are always welcom.",
						"Hold still.","Follow me.","Just follow my lead.","To be honest with you," };
const char* tstr[] = { "こんにちは。","お元気ですか。","おかげさまで。",
						"まあ、なんとか。","始めまして。","さようなら。",
						"おはよう。","こんにちは。","こんばんは。",
						"またね。","どうぞ。","ありがとう。",
						"いいえ、結構です。","お名前をお伺いします。","お会いできて嬉しいです。",
						"何時ですか？","7時くらいです。","もう行かなくちゃ。",
						"いくらですか？","お手洗いはどちらですか。","失礼します。(一人)",
						"失礼します。(複数人)","すみません。","どうだろう。",
						"小銭が手元にありません。","また来ます。","お出かけですか？",
						"おじゃまします。","言い訳はしません。","踊りませんか？",
						"お願いがあるのですが。","とても季節外れですね。","いつでも歓迎します。",
						"じっとしていてください。","ついてきてください。","私の言うとおりにしてください。","正直に言うと…" };
int go(const char* str) {
	int len = (int)strlen(str);
	int mistake = 0;
	for (int i = 0; i < len; i++) {
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (_getch() != str[i]) mistake++;
	}
	return mistake;
}
int go2(const char* str) {
	int len = (int)strlen(str);
	int mistake = 0;
	for (int i = 0; i < len; i++) {
		printf("%s ", &str[i]);
		for (int j = -1; j < len - i; j++) printf("\b");
		fflush(stdout);
		while (_getch() != str[i]) mistake++;
	}
	return mistake;
}
void pos_training(void) {
	int no = 0;
	int i = 0;
	int temp = 0, line = 0;
	int len = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	puts("\n単純ポジショントレーニングを行います。");
	do {
		printf("レベルを選択してください(1～5) : ");
		scanf_s("%d", &no);

	} while (no < 1 && no > 5);
	puts("練習するブロックを選択してください。");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[0], kstr[1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[4], kstr[5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[8], kstr[9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	do {
		printf("番号 (練習中止は99) : ");
		scanf_s("%d", &temp);
		if (temp == 99) return;
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sの問題を%d回練習します。\n", kstr[line], no * 2);

	printf("スペースキーで開始します。\n");
	while (_getch() != ' ');

	len = (int)strlen(kstr[line]);

	start = clock();

	for (int stage = 0; stage < no * 2; stage++) {
		char str[POS_LEN + 1]{};

		for (i = 0; i < POS_LEN; i++) {
			str[i] = kstr[line][rand() % len];
		}
		str[i] = '\0';

		mno += go(str);
		tno += (int)strlen(str);
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("(平均)%.1f秒/タイプ\n", (double)(end - start) / CLOCKS_PER_SEC / tno);
}
void pos_training2(void) {
	int no = 0;
	int i = 0;
	int temp = 0, line = 0;
	int sno = 0;
	int select[KTYPE]{};
	int len[KTYPE]{};
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;
	const char* format = "第%d段 (%2d) 左 %-8s (%2d) 右 %-8s "
		"(%2d)[左] %-8s (%2d)[右] %-8s\n";

	puts("\n複合ポジショントレーニングを行います。");
	do {
		printf("レベルを選択してください(1～5) : ");
		scanf_s("%d", &no);

	} while (no < 1 && no > 5);
	puts("練習するブロックを選択してください(複数選択可)。");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i + 1, k + 1, kstr[k], k + 2, kstr[k + 1],
			k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	while (1) {
		printf("番号 (選択終了は50/練習中止は99) : ");

		do {
			scanf_s("%d", &temp);
			if (temp == 99) return;
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50) break;
		for (i = 0; i < sno; i++) {
			if (temp == select[i]) {
				printf("\aその段はすでに選ばれています。\n");
				break;
			}
		}
		if (i == sno) select[sno++] = temp;
	}

	if (i == sno) return;

	printf("以下のブロックの問題を%d回練習します。\n", no * 2);

	for (i = 0; i < sno; i++) {
		printf("%s ", kstr[select[i] - 1]);
	}
	puts("\nスペースキーで開始します。");
	while (_getch() != ' ');

	for (i = 0; i < sno; i++) {
		len[i] = (int)strlen(kstr[select[i] - 1]);
	}

	start = clock();

	for (int stage = 0; stage < no * 2; stage++) {
		char str[POS_LEN + 1]{};

		for (i = 0; i < POS_LEN; i++) {
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str);
		tno += (int)strlen(str);
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("(平均)%.1f秒/タイプ\n", (double)(end - start) / CLOCKS_PER_SEC / tno);
}
void word_training(const char* mes, const char* str[], int n) {
	int no = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;
	do {
		printf("レベルを選択してください(1～5) : ");
		scanf_s("%d", &no);

	} while (no < 1 && no > 5);

	printf("\n%sを%d個練習します。\n", mes, no * 2);

	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	pno = n;

	start = clock();

	for (int stage = 0; stage < no * 2; stage++) {
		do {
			qno = rand() % n;
		} while (qno == pno);
		mno += go(str[qno]);
		tno += (int)strlen(str[qno]);
		pno = qno;
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
void word_training2(const char* mes, const char* str[], int n) {
	int no = 0;
	int qno = 0, pno = 0;
	int record[NO]{};
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	do {
		printf("レベルを選択してください(1～5) : ");
		scanf_s("%d", &no);

	} while (no < 1 && no > 5);

	printf("\n%sを%d個練習します。\n", mes, no * 2);

	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	pno = n;

	start = clock();

	for (int stage = 0; stage < NO; stage++) {
		do {
			qno = record[stage] = rand() % n;
		} while (qno == pno || record[stage] == pno);
		mno += go(str[qno]);
		tno += (int)strlen(str[qno]);
		pno = qno;
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
void word_training3(const char* mes, const char* str[], int n) {
	int no = 0;
	int qno = 0, pno = 0;
	int record[NO]{};
	int tno = 0, mno = 0;
	int Jflag = 0;
	clock_t start = 0, end = 0;

	do {
		printf("レベルを選択してください(1～5) : ");
		scanf_s("%d", &no);

	} while (no < 1 && no > 5);
	if (mes == "英会話の文書") {
		do {
			printf("日本語訳を表示しますか？(0)いいえ / (1)はい : ");
			scanf_s("%d", &Jflag);
		} while (!(Jflag == 0 || Jflag == 1));
	}

	printf("\n%sを%d個練習します。\n", mes, no * 2);

	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	pno = n;

	start = clock();

	for (int stage = 0; stage < no * 2; stage++) {
		do {
			qno = record[stage] = rand() % n;
		} while (qno == pno || record[stage] == pno);
		if (Jflag) {
			printf("%s	", tstr[qno]);
			mno += go2(str[qno]);
			printf("\r%*s\r", (int)strlen(tstr[qno]) + 1, "");
		}
		else mno += go(str[qno]);
		tno += (int)strlen(str[qno]);
		pno = qno;
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("(平均)%.1f秒/タイプ\n", (double)(end - start) / CLOCKS_PER_SEC / tno);
}
Menu SelectMenu(void) {
	int ch = 0;

	do {
		puts("\n練習を選択してください。");
		puts("(1) 単純ポジション  (2) 複合ポジション");
		printf("(3) C言語の単語    (4) 英会話      (0)終了 : ");
		scanf_s("%d", &ch);
	} while (ch < (int)Menu::Term || ch >= (int)Menu::InValid);

	return (Menu)ch;
}
Menu SelectMenu2(void) {
	int ch = 0;

	do {
		puts("\n練習を選択してください。");
		puts("(1) 単純ポジション  (2) 複合ポジション  (3) C言語の単語");
		printf("(4) 英会話	(5)キー配置連想タイピング  (0)終了 : ");
		scanf_s("%d", &ch);
	} while (ch < (int)Menu::Term || ch >= (int)Menu::InValid);

	return (Menu)ch;
}
Menu SelectMenu3(void) {
	int ch = 0;

	do {
		puts("\n練習を選択してください。");
		puts("(1) 単純ポジション  (2) 複合ポジション  (3) C言語の単語");
		puts("(4) 英会話  (5)キー配置連想タイピング");
		printf("(6) ホームポジション2  (7) ホームポジション3 (0)終了 :  ");
		scanf_s("%d", &ch);
	} while (ch < (int)Menu::Term || ch >= (int)Menu::InValid);

	return (Menu)ch;
}
//8-6
void suggestion() {
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("キー位置連想タイピング練習を始めます。");
	puts("？で隠された文字をタイプしてください");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	start = clock();

	for (int stage = 0; stage < NO; stage++) {
		int k = 0, p = 0, key = 0;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % (int)strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');

		strcpy_s(temp, 10, kstr[k]);
		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (_getch() != key);
		putchar('\n');
	}

	end = clock();

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
void makestr(char a, char b, char* str) {
	for (int n = 0; n < 10; n++) {
		if (n % 2 == 0) str[n] = a;
		else str[n] = b;
	}
}
void makestr2(char a, char b, char c, char* str) {
	for (int n = 0; n < 10; n++) {
		if (n % 3 == 0) str[n] = a;
		else if (n % 3 == 1) str[n] = b;
		else str[n] = c;
	}
}
void homePos2() {
	int i = 0, j = 0;
	int temp = 0, line = 0;
	int len = 0, combination = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	puts("\nホームポジショントレーニングを行います。");
	puts("練習するブロックを選択してください。");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[0], kstr[1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[4], kstr[5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[8], kstr[9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	do {
		printf("番号 : ");
		scanf_s("%d", &temp);
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sを練習します。\n", kstr[line]);

	printf("スペースキーで開始します。\n");
	while (_getch() != ' ');

	len = (int)strlen(kstr[line]);
	combination = len * (len - 1) / 2;


	start = clock();
	//組み合わせを順に問題文字列に変換するループの作成 
	char str[POS_LEN + 1]{};
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			makestr(kstr[line][i], kstr[line][j], str);
			str[10] = '\0';
			mno += go(str);
			tno += (int)strlen(str);

			makestr(kstr[line][j], kstr[line][i], str);
			str[10] = '\0';
			mno += go(str);
			tno += (int)strlen(str);
		}
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("(平均)%.1f秒/タイプ\n", (double)(end - start) / CLOCKS_PER_SEC / tno);
}
void homePos3() {
	int i = 0, j = 0, k = 0;
	int temp = 0, line = 0;
	int len = 0, combination = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	puts("\nホームポジショントレーニングを行います。");
	puts("練習するブロックを選択してください。");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[2], kstr[3]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[6], kstr[7]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[10], kstr[11]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[14], kstr[15]);

	do {
		printf("番号 : ");
		scanf_s("%d", &temp);
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2 + 2;

	printf("%sを練習します。\n", kstr[line]);

	printf("スペースキーで開始します。\n");
	while (_getch() != ' ');

	len = (int)strlen(kstr[line]);
	combination = len * (len - 1) / 2;


	start = clock();
	//組み合わせを順に問題文字列に変換するループの作成 
	char str[POS_LEN]{};
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			for (k = j + 1; k < len; k++) {
				makestr2(kstr[line][i], kstr[line][j], kstr[line][k], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);

				makestr2(kstr[line][i], kstr[line][k], kstr[line][j], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);

				makestr2(kstr[line][k], kstr[line][j], kstr[line][i], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);
			}
		}
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("(平均)%.1f秒/タイプ\n", (double)(end - start) / CLOCKS_PER_SEC / tno);
}


#ifdef _0800
//8-1
void key_typing1() {
	const char* str = "How do you do?";
	int len = (int)strlen(str);
	clock_t start = 0, end = 0;

	puts("この通りにタイプしてください。");
	printf("%s\n", str);
	fflush(stdout);

	start = clock();

	for (int i = 0; i < len; i++) {
		int ch = 0;

		do {
			ch = _getch();
			if (isprint(ch)) {
				putchar(ch);
				if (ch != str[i]) {
					putchar('\b');
				}
			}
		} while (ch != str[i]);
	}

	end = clock();

	printf("\n%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
//8-2
void key_typing2() {
	const char* str = "How do you do?";
	int len = (int)strlen(str);
	clock_t start = 0, end = 0;

	puts("この通りにタイプしてください。");

	start = clock();

	for (int i = 0; i < len; i++) {
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (_getch() != str[i]);
	}
	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
//8-3
void key_types1() {
	const char* str[QNO] = { "book", "computer", "default", "comfort",
							"monday", "power", "light", "music",
							"programming", "dog", "video", "include" };
	clock_t start = 0, end = 0;

	puts("タイピング練習を始めます。");
	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	start = clock();

	for (int stage = 0; stage < QNO; stage++) {
		int len = (int)strlen(str[stage]);
		for (int i = 0; i < len; i++) {
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (_getch() != str[stage][i]);
		}
	}

	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
//8-5
void key_types2() {
	const char* str[QNO] = { "book", "computer", "default", "comfort",
							"monday", "power", "light", "music",
							"programming", "dog", "video", "include" };
	int i = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j) swap(const char*, str[i], str[j]);
	}

	puts("タイピング練習を始めます。");
	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	start = clock();

	for (int stage = 0; stage < QNO; stage++) {
		int len = (int)strlen(str[stage]);
		for (i = 0; i < len; i++) {
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (_getch() != str[stage][i]);
		}
	}

	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
//8-7
void type_training() {
	Menu menu{};
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	srand((unsigned)time(NULL));

	do {
		switch (menu = SelectMenu()) {
		case Menu::KeyPos:
			pos_training();
			break;
		case Menu::KeyPosComp:
			pos_training2();
			break;
		case Menu::Clang:
			word_training("C言語の単語", cstr, cn);
			break;
		case Menu::Conversation:
			word_training("英会話の文書", vstr, vn);
			break;
		}
	} while (menu != Menu::Term);
}

int main(void) {
	type_training();

	return 0;
}
#endif

#ifdef _0801
const char* str[QNO] = { "book", "computer", "default", "comfort",
						"monday", "power", "light", "music",
						"programming", "dog", "video", "include" };
int main(void) {
	int i = 0;
	int qno[QNO]{};
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < QNO; i++) {
		qno[i] = i;
	}
	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j) swap(int, qno[i], qno[j]);
	}

	puts("タイピング練習を始めます。");
	puts("スペースキーで開始します。");
	while (_getch() != ' ');

	start = clock();
	for (int stage = 0; stage < QNO - 2; stage++) {
		int len = (int)strlen(str[qno[stage]]);
		for (i = 0; i < len; i++) {
			printf("%s \r", &str[qno[stage]][i]);
			fflush(stdout);
			while (_getch() != str[qno[stage]][i]);
		}
	}
	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0802
int main(void) {
	Menu menu{};
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	srand((unsigned)time(NULL));

	do {
		switch (menu = SelectMenu()) {
		case Menu::KeyPos:
			pos_training();
			break;
		case Menu::KeyPosComp:
			pos_training2();
			break;
		case Menu::Clang:
			word_training2("C言語の単語", cstr, cn);
			break;
		case Menu::Conversation:
			word_training2("英会話の文書", vstr, vn);
			break;
		}
	} while (menu != Menu::Term);


	return 0;
}
#endif

#ifdef _0803
int main(void) {
	Menu menu{};
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	srand((unsigned)time(NULL));

	do {
		switch (menu = SelectMenu()) {
		case Menu::KeyPos:
			pos_training();
			break;
		case Menu::KeyPosComp:
			pos_training2();
			break;
		case Menu::Clang:
			word_training3("C言語の単語", cstr, cn);
			break;
		case Menu::Conversation:
			word_training3("英会話の文書", vstr, vn);
			break;
		}
	} while (menu != Menu::Term);


	return 0;
}
#endif

#ifdef _0804
int main(void) {
	Menu menu{};
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	srand((unsigned)time(NULL));

	do {
		switch (menu = SelectMenu2()) {
		case Menu::KeyPos:
			pos_training();
			break;
		case Menu::KeyPosComp:
			pos_training2();
			break;
		case Menu::Clang:
			word_training3("C言語の単語", cstr, cn);
			break;
		case Menu::Conversation:
			word_training3("英会話の文書", vstr, vn);
			break;
		case Menu::Suggestion:
			suggestion();
		}
	} while (menu != Menu::Term);


	return 0;
}
#endif

#ifdef _0805
int main(void) {
	int i = 0, j = 0;
	int temp = 0, line = 0;
	int len = 0, combination = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	puts("\nホームポジショントレーニングを行います。");
	puts("練習するブロックを選択してください。");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[0], kstr[1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[4], kstr[5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[8], kstr[9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	do {
		printf("番号 : ");
		scanf_s("%d", &temp);
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sを練習します。\n", kstr[line]);

	printf("スペースキーで開始します。\n");
	while (_getch() != ' ');

	len = (int)strlen(kstr[line]);
	combination = len * (len - 1) / 2;


	start = clock();
	//組み合わせを順に問題文字列に変換するループの作成 
	char str[POS_LEN + 1]{};
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			makestr(kstr[line][i], kstr[line][j], str);
			str[10] = '\0';
			mno += go(str);
			tno += (int)strlen(str);

			makestr(kstr[line][j], kstr[line][i], str);
			str[10] = '\0';
			mno += go(str);
			tno += (int)strlen(str);
		}
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}
#endif

#ifdef _0806
int main(void) {
	int i = 0, j = 0, k = 0;
	int temp = 0, line = 0;
	int len = 0, combination = 0;
	int qno = 0, pno = 0;
	int tno = 0, mno = 0;
	clock_t start = 0, end = 0;

	puts("\nホームポジショントレーニングを行います。");
	puts("練習するブロックを選択してください。");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[2], kstr[3]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[6], kstr[7]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[10], kstr[11]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[14], kstr[15]);

	do {
		printf("番号 : ");
		scanf_s("%d", &temp);
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2 + 2;

	printf("%sを練習します。\n", kstr[line]);

	printf("スペースキーで開始します。\n");
	while (_getch() != ' ');

	len = (int)strlen(kstr[line]);
	combination = len * (len - 1) / 2;


	start = clock();
	//組み合わせを順に問題文字列に変換するループの作成 
	char str[POS_LEN]{};
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			for (k = j + 1; k < len; k++) {
				makestr2(kstr[line][i], kstr[line][j], kstr[line][k], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);

				makestr2(kstr[line][i], kstr[line][k], kstr[line][j], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);

				makestr2(kstr[line][k], kstr[line][j], kstr[line][i], str);
				str[9] = '\0';
				mno += go(str);
				tno += (int)strlen(str);
			}
		}
	}
	end = clock();

	printf("問題 : %d文字/ミス : %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0807
int main(void) {
	Menu menu{};
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	srand((unsigned)time(NULL));

	do {
		switch (menu = SelectMenu3()) {
		case Menu::KeyPos:
			pos_training();
			break;
		case Menu::KeyPosComp:
			pos_training2();
			break;
		case Menu::Clang:
			word_training3("C言語の単語", cstr, cn);
			break;
		case Menu::Conversation:
			word_training3("英会話の文書", vstr, vn);
			break;
		case Menu::Suggestion:
			suggestion();
			break;
		case Menu::HomePos2:
			homePos2();
			break;
		case Menu::HomePos3:
			homePos3();
			break;
		}

	} while (menu != Menu::Term);


	return 0;
}
#endif
