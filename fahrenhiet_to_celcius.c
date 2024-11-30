float toCelcius(float fahrehiet)
{
    return (5.0 / 9.0) * (fahrehiet - 32.0)
}
int main()
{
    float f_value,c_value;
    printf("Enter a fahrenhiet value :");
    scanf("%f",&f_value);
    c_value = toCelcius(f_value);
    printf("fahrenhiet = %.1f converted to celcius = %.1f",f_value,c_value);
}