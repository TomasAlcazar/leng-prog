fn is_leap_year(year: u32) -> bool {
    (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
}

fn show_year_check(year: u32) {
    if is_leap_year(year) {
        println!("{} is a leap year.", year);
    } else {
        println!("{} is not a leap year.", year);
    }
}

fn calc_mean(numbers: &[f64]) -> f64 {
    let sum: f64 = numbers.iter().sum();
    sum / (numbers.len() as f64)
}

fn is_prime(num: i32) -> bool {
    if num <= 1 {return false;}
    for i in 2..num {
        if num % i == 0 {return false;}
    }
    true
}

fn merge_sorted(a: &[i32], b: &[i32]) -> Vec<i32> {
    let mut i = 0;
    let mut j = 0;
    let mut out = Vec::with_capacity(a.len() + b.len());

    while i < a.len() && j < b.len() {
        if a[i] <= b[j] {
            out.push(a[i]); i += 1;
        } else {
            out.push(b[j]); j += 1;
        }
    }
    out.extend_from_slice(&a[i..]);
    out.extend_from_slice(&b[j..]);
    out
}

use std::io;

fn factorial(n: i32) -> Result<u64, String> {
    if n < 0 {
        return Err("El factorial no está definido para números negativos".to_string());
    }
    Ok(match n {
        0 | 1 => 1,
        _ => n as u64 * factorial(n - 1)?,
    })
}

fn main() {
    show_year_check(2020);
    show_year_check(2021);
    show_year_check(1900);
    show_year_check(2000);

    let nums = [1.0, 3.0, 4.0, 6.0];
    let mean = calc_mean(&nums);
    println!("Mean of {:?} is {}", nums, mean);

    let prime_check = 29;
    if is_prime(prime_check) {
        println!("{} is a prime number.", prime_check);
    } else {
        println!("{} is not a prime number.", prime_check);
    }

    let arr1 = [1, 3, 5, 7];
    let arr2 = [2, 4, 6, 8];
    let merged = merge_sorted(&arr1, &arr2);
    println!("Merged array: {:?}", merged);

    println!("Enter a number to compute its factorial:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let num: i32 = input.trim().parse().expect("Please enter a valid integer
");    match factorial(num) {
        Ok(result) => println!("Factorial of {} is {}", num, result),
        Err(e) => println!("{}", e),
    }
}