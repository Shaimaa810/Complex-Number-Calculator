#include<bits/stdc++.h>
using namespace std;
string complex_num;
int id_sign1 = 0, id_sign2 = 0, id_i1 = 0, id_i2 = 0;
char operation = ' ', sign_real_num1 = ' ', sign_real_num2 = ' ', sign_imaginary_num1 = ' ', sign_imaginary_num2 = ' ';
float real_num1 = 0, real_num2 = 0, imaginary_num1 = 0, imaginary_num2 = 0 ;
bool valid_complex(string complex_num)
{
    regex valid("[(][-]?[0-9]+(.[0-9]+)?[+-][0-9]+(.[0-9]*)?[i][)][ ][+-]?[/*]?[ ][(][-]?[0-9]+(.[0-9]+)?[+-][0-9]+(.[0-9]*)?[i][)]");
    return regex_match(complex_num,valid);
}
void parsial(string complex_num,char &operation,char &sign_real_num1,char &sign_real_num2,char &sign_imaginary_num1,char &sign_imaginary_num2,int &id_sign1, int &id_sign2,int &id_i1, int &id_i2,float &real_num1, float &real_num2, float &imaginary_num1, float &imaginary_num2)
{
    string sub;
    if(isdigit(complex_num[1]))
    {
        for(int i=0; i<complex_num.size(); i++)
        {
            if((complex_num[i]=='+' || complex_num[i]=='-') && i!=1)
            {
                id_sign1 = i;  
                sign_imaginary_num1 = complex_num[i];
                break;
            }
        }
        sign_real_num1 = '+';
        sub = complex_num.substr(1,id_sign1 - 1);
        real_num1 = stof(sub);
        id_i1 = complex_num.find('i');
        sub = complex_num.substr(id_sign1+1,id_i1-id_sign1);
        imaginary_num1 = stof(sub);
        if(sign_imaginary_num1 == '-')
            imaginary_num1 *= -1;
        operation = complex_num[id_i1+3];
    }
    else
    {
        for(int i=0; i<complex_num.size(); i++)
        {
            if((complex_num[i]=='+' || complex_num[i]=='-') && i!=1)
            {
                id_sign1 = i;
                sign_imaginary_num1 = complex_num[i];
                break;
            }
        }
        sign_real_num1 = '-';
        sub = complex_num.substr(2,id_sign1 - 1);
        real_num1 = (stof(sub))*-1;
        id_i1 = complex_num.find('i');
        sub = complex_num.substr(id_sign1+1,id_i1-id_sign1);
        imaginary_num1 = stof(sub);
        if(sign_imaginary_num1 == '-')
            imaginary_num1 *= -1;
        operation = complex_num[id_i1+3];
    }
    if(isdigit(complex_num[id_i1+6]))
    {
        for(int i=id_i1+6; i<complex_num.size(); i++)
        {
            if(complex_num[i]=='+' || complex_num[i]=='-')
            {
                id_sign2 = i;
                sign_imaginary_num2 = complex_num[i];
                break;
            }
        }
        sign_real_num2 = '+';
        sub = complex_num.substr(id_i1+6,id_sign2 - 1);
        real_num2 = stof(sub);
        id_i2 = complex_num.rfind('i');
        sub = complex_num.substr(id_sign2+1,id_i2-id_sign2);
        imaginary_num2 = stof(sub);
        if(sign_imaginary_num2 == '-')
            imaginary_num2 *= -1;
    }
    else
    {
        for(int i=id_i1+6; i<complex_num.size(); i++)
        {
            if((complex_num[i]=='+' || complex_num[i]=='-') && i != id_i1+6)
            {
                id_sign2 = i;
                sign_imaginary_num2 = complex_num[i];
                break;
            }
        }
        sign_real_num2 = '-';
        sub = complex_num.substr(id_i1+7,id_sign2 - 1);
        real_num2 = (stof(sub))*-1;
        id_i2 = complex_num.rfind('i');
        sub = complex_num.substr(id_sign2+1,id_i2-id_sign2);
        imaginary_num2 = stof(sub);
        if(sign_imaginary_num2 == '-')
            imaginary_num2 *= -1;
    }
}
void sum()
{
    float sum_real = 0, sum_img = 0;
    sum_real = real_num1 + real_num2;
    sum_img = imaginary_num1 + imaginary_num2;
    if(sum_img >= 0)
        cout<<complex_num<<" = ("<<sum_real<<" + "<<sum_img<<"i)";
    else
        cout<<complex_num<<" = ("<<sum_real<<" - "<<sum_img*-1<<"i)";
}
void subtraction()
{
    float subtraction_real = 0, subtraction_img = 0;
    subtraction_real = real_num1 - real_num2;
    subtraction_img = imaginary_num1 - imaginary_num2;
    if(subtraction_img >= 0)
        cout<<complex_num<<" = ("<<subtraction_real<<" + "<<subtraction_img<<"i)";
    else
        cout<<complex_num<<" = ("<<subtraction_real<<" - "<<subtraction_img*-1<<"i)";
}
void multiplication()
{
    float mul_real = 0, mul_img = 0;
    mul_real = (real_num1 * real_num2) + ((imaginary_num1 * imaginary_num2)*-1);
    mul_img = (real_num1 * imaginary_num2) + (imaginary_num1 * real_num2);
    if(mul_img >= 0)
        cout<<complex_num<<" = ("<<mul_real<<" + "<<mul_img<<"i)";
    else
        cout<<complex_num<<" = ("<<mul_real<<" - "<<mul_img*-1<<"i)";
}
void division()
{
    float denominator = pow(real_num2,2)-(imaginary_num2 * imaginary_num2*-1);
    imaginary_num2 *= -1;
    float numerator_real = (real_num1 * real_num2) + ((imaginary_num1 * imaginary_num2)*-1);
    float numerator_img = (real_num1 * imaginary_num2) + (imaginary_num1 * real_num2);
    numerator_real /= denominator;
    numerator_img /= denominator;
    if(numerator_img>=0)
        cout<<complex_num<<" = ("<<numerator_real<<" + "<<numerator_img<<"i)";
    else
        cout<<complex_num<<" = ("<<numerator_real<<" - "<<numerator_img*-1<<"i)";
}
int main()
{
    cout<<"please enter a complex number operations in the form (n1+or-n2i) operation (n3+or-n4i) without spaces between real and imaginary parts\n";
    getline(cin,complex_num);
    if(valid_complex(complex_num))
    {
        parsial(complex_num,operation,sign_real_num1,sign_real_num2,sign_imaginary_num1,sign_imaginary_num2,id_sign1,id_sign2,id_i1, id_i2,real_num1, real_num2,imaginary_num1,imaginary_num2);
        if(operation == '+')
            sum();
        else if(operation == '-')
            subtraction();
        else if(operation == '*')
            multiplication();
        else if(operation == '/')
            division();
    }
    else
        cout<<"Invalid operand or missing brackets. Try again.\n";

    return 0;
}


