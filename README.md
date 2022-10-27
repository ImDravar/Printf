# ft_printf

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](http://forthebadge.com)
[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)
<a href="https://projects.intra.42.fr/42cursus-ft_printf/rruiz-sa"> <img width="179" height="35" src="https://drive.google.com/uc?export=view&id=1EG-VjzsMBvmJpZ0euI2wt6qexoJ0UlEU"> </a>
<a href="https://github.com/xicodomingues/francinette"> <img width="179" height="35" src="https://drive.google.com/uc?export=view&id=1DuBGIcoOQsgsBgb-BAJn3UIDbkcSd-vJ"> </a>
<a href="https://www.linkedin.com/in/rruiz-sa/"> <img width="120" height="35" src="https://upload.wikimedia.org/wikipedia/commons/0/01/LinkedIn_Logo.svg"> </a>

![printf drawio](https://user-images.githubusercontent.com/107029910/198342569-d124efee-76ae-4e93-9fc8-85105bf3e90b.png)

The goal of this project is to reprogram [printf()](https://man7.org/linux/man-pages/man3/printf.3.html).
We will learn how to use a variable number of arguments.


# Table of contents

- [Mandatory part](#mandatory)
  - [Flags](#flags)
    - `%c`
    - `%s`
    - `%p`
    - `%u`
    - `%%`
    - `%d` && `%i`
    - `%x` && `%X`
  - [Utils](#utils)
    - `ft_putchar`
    - `ft_minmax`
    
# Mandatory part

| Program name  | libftprintf.a |
| ------------- | ------------- |
| Turn in files |Makefile, *.h, */*.h, *.c, */*.c  |
| Makefile  | NAME, all, clean, fclean, re  |
| External functions  | malloc, free, write,va_start, va_arg, va_copy, va_end  |


### Flags

#### - With `%c` : Prints a single character.
   
 ```
[Description ft_printf_c]
    1- Call [ft_putchar] and send the char passed by parameter AND return their value (the number of bytes printed)
```

#### - With `%s` : Prints a string (as defined by the common C convention).

 ```
[Description ft_printf_s]
  1- Check If the string exist
    {If exist}
      a- Iterate the string, call [ft_putchar] each iteration
      b- And each iteration check if the writing is correct,if its Incorrect return -1
  {If doesn't}
    A- Counter its equal to size of the str "(null)"
    B- Call [ft_printf_s] and send by parameter "(null)"
    C- Check the return of [ft_printf_s] if its Incorrect return -1
  2- If the param "check_malloc" its 1 free the str
  3- Return counter
 ```
    
#### - With `%p` : The void * pointer argument has to be printed in hexadecimal format.

 ```
[Description ft_printf_p]
  1- Check If the number passed by parameter exist
    {If doesn't}
      a- Call [ft_printf_s] ans send "0x0"
      b- Check if the return of the [ft_printf_s] its incorrect,if its, return -1
    {If exist}
      A- Call [ft_printf_s] ans send "0x"
      B- Check if the return of the [ft_printf_s] its incorrect,if its, return -1
      C- Call [ft_printf_p_num] ans send the number and the hex base
      
[Description ft_printf_p_num]
  1- Check If the number passed by parameter is < 16
    {If its}
      a- Call [ft_putchar] and send the char of the hex base
      b- Check if the return of the [ft_putchar] its incorrect,if its, return -1
      c- Increase the counter
    {If its not}
      A- Send to [ft_printf_p_num] the num / 16 and the base and save the return
      B- Send to [ft_printf_p_num] the num % 16 and the base and save the return
      C- Check if the return of A or B its incorrect, if its, return -1
      D- Sum the return of A + B to the counter and to itself
  2- Return the counter
 ```
 
#### - With `%u` : Prints an unsigned decimal (base 10) number.

 ```
[Description ft_printf_u]
  0- Transform the number in positive [ft_minmax]
  1- Get the len of the number [ft_numlen_easy]
  2- Create (and check)the malloc with the len
  3- Close the string
  4- Check if the number is equal to 0, if it is, put in the position 0 the character
  5- Iterate while num exist.Each iteration
    - Put the mod(in char) of the number in the string
    - The number is the result of dividing itself by 10
  6- Call [ft_printf_s] and send the str with the param for free the str
  7- Check the return of [ft_printf_s] if fails free the str
  8- Return the [ft_printf_s] value.

[Description ft_numlen_easy]
  1- Check if number its equal a 0, if it is, return 1
  2- Iterate while number exist, at the end return the iteration counter.
 ```
 
#### - With `%%` : Prints a percent sign.

 ```
[Description ft_printf_37]
  1- Call [ft_putchar] with the '%' AND return their value (the number of bytes printed)
  ```
#### - With `%d` OR `%i`
  * With `%d` : Prints a decimal (base 10) number.
  * With `%i` : Prints an integer in base 10.

```
[Description ft_printf_di]
  1- Get the len of the number (call ft_numlen)
  2- Create (and check)the malloc with the len
  3- Close the string
  4- Check if the number is equal to 0,if it is, put in the position 0 the character
  5- Check if the number is negative,if it is, transform in positive and put in pos 0 the '-'
  6- Iterate while num exist.Each iteration
    - Put the mod(in char) of the number (previusly transformed in positive) inside the string
    - The number is the result of dividing itself by 10
  7- Call [ft_printf_s] and send the str with the param for free the str
  8- Check the return of [ft_printf_s] if fails free the str
  9- Return the [ft_printf_s] value.

 [Description ft_numlen]
  1- Check if number its equal a 0, if it is, return 1
  2- Check if the number its negative, if its is, increase 1 the counter and transfor the number in positive
  3- Iterate while number exist, at the end return the iteration counter.
```

#### - With `%x` OR `%X`
  * With `%x` : Prints a number in hexadecimal (base 16) lowercase format.
  * With `%X` : Prints a number in hexadecimal (base 16) uppercase format.

```
[Description ft_printf_x]
  1- Check if number < 16
    {If it is}
      a- Call [ft_putchar] and send the char of the base
      b- Check if the return of [ft_putchar] its correct, if not return -1
      c- Increase the counter
    {If not}
      A- Call with recursivity [ft_printf_x] send the num/16 and the base
      B- Check if the return its correct, if its not return -1
      C- Call with recursivity [ft_printf_x] send num%16 and the base
      D- Check if the return its correct, if its not return -1
      E- Increase the counter with the sum of the return A+B
  2- Return the counter
 ```   
### Utils

#### - Function `ft_putchar` : 

```
[Description ft_putchar]
  1- Write the character passed by parameter AND check if the writing its correct
  2- If its incorrect return -1 , it its correct return 1;
```

#### - Function `ft_minmax` : 

```
[Description ft_minmax]
  1- If the number is negative, transform in positive
```
# License

<a href="https://creativecommons.org/licenses/by-sa/4.0/deed.en"> <img width="250" height="35" src="https://drive.google.com/uc?export=view&id=13KzHIgBtdtkPKyk5lBtR6eAgnLZsrHOc "> </a>

Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)

#### You are free to:
  * **Share** — copy and redistribute the material in any medium or format
  * **Adapt** — remix, transform, and build upon the material for any purpose, even commercially.
 
#### Under the following terms:
* **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

* **ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

* **No additional restrictions** — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.

