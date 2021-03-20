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
        let input = scan.next::<String>();
        let mut s:Vec<char> = vec!['\0';0];
        for c in input.chars() {
            s.push(c);
        }
        if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') ||
           (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') ||
           (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
           (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
           (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}