#include <stdio.h>
#include <stdlib.h>
void menu(){ //تابع void بدون خروجی(بدون بازگشتی) برای نمایش اعلان کل منو و بدون ورودی(آرگومان)
    printf("[0] Quit\n");
    printf("[1] Calendar\n");
    printf("[2] Age\n");
    printf("-------------------------\n");
    printf("Select Option: ");
}
void Calendermenu(){
//تابع بدون خروجی برای نمایش اعلان منو تاریخ و بدون ورودی
//کد و دستوری ندارن چون وقتی دستور می نوشتیم ورودی ها درست چاپ نمی شدن و درست گرفته نمی شدن منظور از درست چاپ نمی شدن اینکه ورودی رو زیر نوشته های اینتر یور فلان می نوشت و میگرفت

}
void Agemenu(){

//تابع  بازهم بدون خروجی برای نمایش اعلان منوی سن و بدون ورودی


}
//تابع دارای آرگومان(دارای ورودی) و دارای خروجی(بازگشتی) و برای محاسبه سال که در ورودی می دهیم کبیسه است یا نه
int is_kab(int year){
    if (year % 400 == 0){
        return 1;
    }else if (year % 100 == 0){
        return 0;
    }else if (year % 4 == 0){
        return 1;
    }else{
        return 0;
    }
}// تابعی برای فهمیدن اینکه آیا سالی که در ورودی داده ایم کبیسه است یا عادی که نشان دهد روزهای آن را که اگر کبیسه بود در ماه اسفند یا همان ماه12 روز های آن ماه 29 است یا 30 اگر کبیسه بود و در ماه های مابقی 30 اند یا 31 و تابع هم با آرگومان است و هم دارای خروجی
int days_month(int month , int year){
    switch (month){
        case 12:
        return is_kab(year) ? 30 : 29;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            return 30;
        default:
            return 31;
    }
}// تابع بدون بازگشتی(بدون خروجی) و با آرگومان(با ورودی) برای چاپ چگونگی تقویم که روز های هفته چگونه باشد و روز ها چگونه باشند و نام ماه های آن
void print_calender(int year , int month){
    char* months[12] = {"Farvardin", "Ordibehesht", "Khordad", "Tir", "Mordad", "Shahrivar", "Mehr", "Aban", "Azar", "Dey", "Bahman", "Esfand"};//استفاده از pointer
    int i , day_of_week;
    int days_of_month = days_month(month , year);
    day_of_week = (2 + (13 * (month + 12)) / 5 + year + (year / 4) - (year / 100) + (year / 400)) % 7;// فرمول چگونگی روز های هفته
    printf("        %s\n" , months[month]);
    printf("SH YE DO SE CH PA JO\n");
    for (i = 0; i <day_of_week; i++){
        printf("   ");//برای فاصله روز های ماه که در یک فرم باشند
    }
    for (i = 1; i <= days_of_month; i++){
        printf("%2d " , i);//این 2 نشان دهنده عرض روز های است یا عرض فاصله ستونی اعداد روز های ماه
        if ((i + day_of_week) % 7 == 0){
            printf("\n");
        }
    }
    printf("\n");
}
void seen(int birthyear , int birthmonth , int birthday){//تابع آرگومانی و بدون خروجی برای محاسبه سن  و دادن ورودی تاریخ امروز و تشخیص اینکه عدد هایی که وارد میکنیم درست است یا غلط
    int salalan , mahalan , rozalan;
    printf("Tarikh emroz ro benevis ma darim zahmat mikeshim(fargi nadare chi benevisi):");
    scanf("%d" , &salalan);
    scanf("%d" , &mahalan);
    scanf("%d" , &rozalan);
    if (mahalan < 1 || mahalan > 12 || rozalan < 1 || rozalan > 31 || birthmonth < 1 || birthmonth > 12 || birthday < 1 || birthday > 31){
        printf("Invalid input !\n");
        return;
    }
    int ageyear , agemonth , ageday;//فرمولی برای محاسبه سن که با تاریخ امروز و تاریخ تولد  کار دارد و با آن ها سن شما با ماه و روز چند روز از آن سپری شده است
    if (rozalan >= birthday){
        ageday = rozalan - birthday;
        if (mahalan >= birthmonth){
            agemonth = mahalan - birthmonth;
            ageyear = salalan - birthyear;
        }else{
            agemonth = mahalan + 12 - birthmonth;
            ageyear = salalan - birthyear - 1;
        }
    }else{
        if (mahalan > birthmonth){
            ageday = rozalan + 30 - birthday;
            agemonth = mahalan - 1 - birthmonth;
            ageyear = salalan - birthyear;
        }else{
            ageday = rozalan + 30 - birthday;
            agemonth = mahalan + 11 - birthmonth;
            ageyear = salalan - 1 - birthyear;
        }
    }
    printf("Age: %d years, %d months, %d days\n" , ageyear , agemonth , ageday);//چاپ سن فرد

    printf("Days passed: %d days\n" , (ageyear * 365));// فرمولی برای روز های گذشته شده از عمر انسان و چاپ آن

    printf("Birth day is on: ");//چاپ چه روزی است تولد فرد

    switch ((birthyear + birthmonth * 100 + birthday) % 7){//روشی برای نشان دادن روز تولد فرد برای هم میلادی و هم شمسی و هم قمری با سویچ کیس
        case 1:
        if(salalan > 1500){
        printf("Saturday");
        }else{
            printf("Shanbe");
        }
        break;
        case 2:
        if (salalan > 1500){
            printf("Sunday");
        }else{
            printf("Yekshanbe");
        }
        break;
        case 3:
        if (salalan > 1500){
            printf("Monday");
        }else{
            printf("Doshanbe");
        }
        break;
        case 4:
        if (salalan > 1500){
            printf("Tuesday");
        }else{
            printf("Seshanbe");
        }
        break;
        case 5:
        if (salalan > 1500){
            printf("Wednesday");
        }else{
            printf("Cheharshanbe");
        }
        break;
        case 6:
        if (salalan > 1500){
            printf("Thursday");
        }else{
            printf("Panjshanbe");
        }
        break;
        case 7:
        if (salalan > 1500){
            printf("Friday");
        }else{
            printf("Jome");
        }
        break;
    }
    printf("\n");
}


int main (){//تابع اصلی برای نمایش همه چیز از منو و تاریخ و محاسبه سن و کد های آن ها
    int choise;
    while (1){// 1 همان true هست که میتونستیم در اول کد با define هم بنویسیم بجای 1 true 
        menu();//call کردن تابع منو
        scanf("%d" , &choise);
        if (choise < 0 || choise > 2){
            printf("Invalid input!\n");
            continue;
        }
        switch (choise){//سویچ کیس برای همه چیز منو از ورودی های اشتباه تا انتخاب گزیمه مورد نظر
            case 0:
            printf("Bye!\n");
            return 0;
            case 1:
            Calendermenu();//صدا زدن تابع منو تاریخ برای اجرای منو و کد های آن
            int year , month;

            printf("Enter Year: ");
            scanf("%d" , &year);// گرفتن سال تاریخ

            printf("Enter Month: ");
            scanf("%d" , &month);// گرفتن ما تاریخ
            while (year == 0 || month == 0 || month > 12){
                printf("Enter Month: ");
                scanf("%d" , &month);

                continue;
            }
            print_calender(year , month - 1);// /0 این رو حساب نکنه صدا زدن تابع چاپ تاریخ و ماه رو یکی کم میکنک که چون 
             printf("Enter Month: ");
             scanf("%d" , &month);
             print_calender(year , month - 1);

             printf("Enter Month: ");
             scanf("%d" , &month);
             print_calender(year , month -1);
                
            break;// وقتی ماه رو منهای یک نمی کردم بجای ماه اول که فروردین بود مینوشت اردیبهشت
                
            case 2:

            Agemenu();// صدا زدن تابع منو سن
            int birthyear , birthmonth , birthday;

            printf("Enter your birth year: ");

            scanf("%d" , &birthyear);// گرفتن سال تولد

            printf ("Enter your birth month: ");

            scanf("%d" , &birthmonth);// گرفتن ماه تولد

            printf("Enter your birth day: ");

            scanf("%d" , &birthday);// گرفتن روز تولد


            if (birthyear == 0 || birthmonth == 0 || birthday == 0){// بررسی اشتباه وارد کردن ورودی ها و چاپ اشتباه دادن آن ها
                printf("--------------------------\n");
                printf("Back to menu!\n");
                continue;
            }
            seen(birthyear , birthmonth , birthday);// صدا زدن تابع محاسبه سن
                printf("--------------------------\n");
                printf("Back to menu!\n");
            break;

        }
    }
    return 0;

}// پایان کد
