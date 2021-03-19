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
        let b:Vec<u32> = (0..n).map(|_| scan.next()).collect();
        let mut a:Vec<u32> = vec![0; n];
        for i in 0..((n + 1) >> 1) {
            a[i << 1] = b[i];
        }
        for i in 0..(n >> 1) {
            a[(i << 1) + 1] = b[n - i - 1];
        }
        for x in a {
            write!(out, "{} ", x).ok();
        }
        writeln!(out, "").ok();
    }
}