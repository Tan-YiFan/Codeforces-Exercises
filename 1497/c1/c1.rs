/* https://codeforces.com/blog/entry/67391 */
#[allow(unused_imports)]
use std::cmp::{min, max};
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t:usize = scan.next();
    for _ in 0..t {
        let n:usize = scan.next();
        let _k:usize = scan.next();
        if n & 1 == 1 {
            writeln!(out, "{} {} {}", 1, n >> 1, n >> 1).ok();
        } else if n % 4 == 0 {
            writeln!(out, "{} {} {}", n >> 1, n >> 2, n >> 2).ok();
        } else {
            writeln!(out, "{} {} {}", 2, (n >> 1) - 1, (n >> 1) - 1).ok();
        }
    }
}