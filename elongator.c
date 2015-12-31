#include<stdio.h>

 main()
{   
    /*
     two songs named x and y ( in the d drive ) are elongated and copied into the third file named y.mp3
    */
    FILE *fp1, *fp2;
    char ch;
    int pos;
 
    fp1 = fopen("D:/x.mp3","rb");    
    fp2 = fopen("D:/y.mp3", "wb");
    fseek(fp1,0,SEEK_END);
    pos=ftell(fp1);          // gives number of characters present in the input file
    fseek(fp1,0,SEEK_SET);
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    }    
    fclose(fp1);
    fp1 = fopen("D:/z.mp3","rb");           
    fseek(fp1,0,SEEK_END);
    pos=ftell(fp1); 
    fseek(fp1,0,SEEK_SET);
    fseek(fp2,0,SEEK_END);
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    } 
	fclose(fp1);  
    fclose(fp2);    
    return 0;
}
