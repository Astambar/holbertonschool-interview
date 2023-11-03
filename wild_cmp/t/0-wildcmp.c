#include <stdio.h>
#include <string.h>

int wildcmp(char *s1, char *s2)
{
	int identicalstricte = s1 == s2;

	if(identicalstricte)
	  return identicalstricte;
	return 0;

}

int main()
{
	int valide = wildcmp("test", "test");
	int unvalide = wildcmp("test1", "test2");
	printf("valide result: %d \n" , valide);
	printf("unvalide result: %d \n" , unvalide);
}
