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

    let t:u32 = scan.next();
    for _ in 0..t {
        let n:usize = scan.next();
        let mut b:Vec<i32> = (0..n).map(|_| scan.next()).collect();
        b.sort();
        let mut c:Vec<i32> = vec![0;0];
        let mut d:Vec<i32> = vec![0;0];
        for (i, x) in b.iter().enumerate() {
            if i == 0 || b[i] != b[i - 1] {
                c.push(*x);
            } else {
                d.push(*x);
            }
        }
        for x in c.iter() {
            write!(out, "{} ", x).ok();
        }
        for x in d.iter() {
            write!(out, "{} ", x).ok();
        }
        writeln!(out, "").ok();
    }
}

