fn gcd_recursion(a: i64, b: i64) -> i64 {
    match a % b {
        0 => b,
        _ => gcd_recursion(b, a % b)
    }
}

fn gcd(mut a: i64, mut b: i64) -> i64 {
    loop {
        if a % b == 0 {
            break b
        }

        b = a % b;
        a = b;
    }
}

fn main() {
    println!("Greatest common divisor(recursion): {}", gcd_recursion(24i64, 22i64));
    println!("Greatest common divisor: {}", gcd(16i64, 12i64));
}
