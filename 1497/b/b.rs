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
        let m:usize = scan.next();
        let a:Vec<usize> = (0..n).map(|_| scan.next::<usize>() % m).collect();
        let mut num:Vec<i32> = vec![0; m];
        for x in a {
            num[x] += 1;
        }
        // writeln!(out, "{:?}", num).ok();
        let mut ans = 0;
        for i in 0..m {
            if num[i] == 0 {
                continue;
            }
            if i == 0 {
                ans += 1;
                continue;
            }
            if num[m - i] == 0 {
                ans += num[i];
                num[i] = 0;
                continue;
            }
            ans += 1;
            if num[i] < num[m - i] {
                num[m - i] -= num[i] + 1;
                num[i] = 0;
            } else {
                num[i] -= num[m - i] + 1;
                num[m - i] = 0;
                ans += max(0, num[i]);
            }
        }
        writeln!(out, "{}", ans).ok();

    }
}