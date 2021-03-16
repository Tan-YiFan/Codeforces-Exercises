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

#[allow(dead_code)]
#[allow(unused_variables)]
const N:usize = 100000 + 5;
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scan.next::<usize>();
    for _ in 0..t {
        let n = scan.next::<usize>();
        let mut a:Vec<i32> = (0..n).map(|_| scan.next()).collect();

        let mut ans:Vec<i32> = (0..n).map(|_| 0).collect();
        /* for i in 0..n {
            write!(out, "{} ", a[i]).ok();
        } */
        for i in (0..n).rev() {
            /* write!(out, "a[{}] = {}\n", i, a[i]).ok(); */
            if a[i] > 0 {
                /* write!(out, "{}: ok\n", i).ok(); */
                ans[i] = 1;
                if i > 0 {
                    a[i - 1] = max(a[i - 1], a[i] - 1);
                }
            }
        }
        for i in 0..n {
            write!(out, "{}", ans[i]).ok();
            if i == n - 1 {
                write!(out, "{}", '\n').ok();
            } else {
                write!(out, "{}", ' ').ok();
            }
        }
    }
}