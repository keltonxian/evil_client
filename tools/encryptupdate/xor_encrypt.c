#include <stdio.h>
#include <string.h>

int e1(char *string, const char *value, size_t size, char *key)
{
	size_t kindex = 0;
	size_t keylen = strlen(key);
	for (int i = 0; i < size; i++)
	{
		string[i] = value[i] ^ key[kindex];
		if (++kindex >= keylen)
		{
			kindex = 0;
		}
	}
	return 0;
}

int te1(const char *value, size_t size, char *key, int (*func)(char *, const char*, size_t, char *))
{
	char s1[50] = {0};
	memset(s1, 0, 50);
	func(s1, value, strlen(value), key);
	printf("encrypt : [%s][%lu]\n", s1, strlen(s1));

	char s2[50] = {0};
	memset(s2, 0, 50);
	func(s2, s1, strlen(s1), key);
	printf("decrypt : [%s][%lu]\n", s2, strlen(s2));
	return 0;
}

int test1()
{
	char *key = "471028";
	const char *value = "abcdefghijklmn";
	printf("test1 value[%s][%lu], key[%s][%lu]\n", value, strlen(value), key, strlen(key));
	te1(value, strlen(value), key, &e1);
	return 0;
}

int encrypt_file(char *from, char *to)
{
	char *key = "471028";
	FILE *fp;
	FILE *fp1;
	char *p = from;
	char *temp = to;
	if (NULL == (fp = fopen(p, "rb")) || NULL == (fp1 = fopen(temp, "wb")))
	{
		printf("load file[%s] fail", p);
		return 0;
	}
	char str[10] = {0};
	memset(str, 0, 10);
	char ch = fgetc(fp);
	char *k = key;
	while (!feof(fp))
	{
		k = key;
		while ( *k != '\0' && !feof(fp))
		{
			ch = ch ^ *k++;
			//printf("ch[%c]\n", ch);
			fputc(ch, fp1);
			ch = fgetc(fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}

int get_fname(char *output, size_t len_output, const char *filename)
{
	memset(output, 0, len_output);
	size_t len = strlen(filename);
	int pos = -1;
	char f[40] = {0};
	memset(f, 0, 40);
	//printf("len[%zu]\n", len);
	for (int i = len - 1; i >= 0; i-- )
	{
		char c = filename[i];
		//printf("c[%c]\n", c);
		if (c == '.')
		{
			pos = i;
			break;
		}
	}
	if (-1 == pos)
	{
		return -1;
	}
	char *r = strncpy(f, filename, pos);
	//printf("r[%s],f[%s],len_output[%zu]\n", r, f, strlen(output));
	snprintf(output, len_output, "%s.evil", f);
	return 0;
}

int main(int argc, const char *argv[])
{
	if (argc < 4)
	{
		printf("please input the filename for encrypt");
		return 0;
	}
	const char *input_folder = argv[1];
	const char *output_folder = argv[2];
	for (int i = 3; i < argc; i++)
	{
		const char *filename = argv[i];
		char input[100] = {0};
		memset(input, 0, 100);
		sprintf(input, "%s/%s", input_folder, filename);
		char out_filename[50] = {0};
		int ret = get_fname(out_filename, 50, filename);
		if (0 != ret)
		{
			printf("error get_fname by [%s], ret[%d]", filename, ret);
			break;
		}
		char output[100] = {0};
		memset(output, 0, 100);
		sprintf(output, "%s/%s", output_folder, out_filename);
		encrypt_file(input, output);
		printf("encrypt_file: %s\n", output);
		/**
		char output[100] = {0};
		int ret = get_fname(output, 100, filename);
		printf("get_fname ret[%d]\n", ret);
		if (0 == ret)
		{
			encrypt_file((char *)filename, output);
			printf("encrypt_file: %s\n", output);
		}
		*/
		/**
		std::string filename(arg);
		size_t pos = filename.rfind(".lua");
		if (pos != std::string::npos)
		{
			filename = filename.substr(0, pos);
		}
		filename.append(".evil");
		encrypt_file(arg, filename);
		*/
	}
	// encrypt_file("game.lua", "game.evil");

	return 0;
}
