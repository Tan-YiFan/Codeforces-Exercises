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

const N:usize = 100000 + 10;
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let mut t:Vec<i32> = vec![0;N];
    let mut x:Vec<i32> = vec![0;N];

    let times = scan.next::<i32>();
    for _ in 0..times {
        let n = scan.next::<usize>();
        let mut ans = 0;

        for i in 1..=n {
            t[i] = scan.next();
            x[i] = scan.next();
        }
        t[n + 1] = 0;
        let mut remaining:i32 = 0;
        let mut cur:i32 = 0;
        let mut direction:i32 = 0;
        for i in 1..=n {
            if success(cur, t[i], t[i + 1], direction, x[i], remaining) {
                ans += 1;
                // writeln!(out, "{} ok", i).ok();
            }
            if remaining > 0 {
                cur = {
                    if direction == 1 {
                        cur + min(remaining, t[i + 1] - t[i])
                    } else {
                        cur - min(remaining, t[i + 1] - t[i])
                    }
                };
                remaining -= t[i + 1] - t[i];
                if remaining <= 0 {
                    direction = 0;
                }
            } else {
                remaining = abs(cur - x[i]) - (t[i + 1] - t[i]);
                if remaining > 0 {
                    direction = {
                        if x[i] > cur {
                            1
                        } else {
                            -1
                        }
                    };
                    cur = {
                        if direction == 1 {
                            cur + (t[i + 1] - t[i])
                        } else {
                            cur - (t[i + 1] - t[i])
                        }
                    }
                } else {
                    direction = 0;
                    cur = x[i];
                }
            }
            // writeln!(out, "cur:{}, dir:{}, remain:{}", cur, direction, remaining).ok();
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn success(cur:i32, x:i32, y:i32, direction:i32, object:i32, remaining:i32) -> bool {
    if direction == 1 {
        if object < cur || cur + remaining < object {
            return false;
        }
        if object - cur <= y - x || y == 0 {
            return true;
        } else {
            return false;
        }
    } 
    if direction == -1 {
        if object > cur || cur - remaining > object {
            return false;
        }
        if cur - object <= y - x || y == 0 {
            return true;
        } else {
            return false;
        }
    }
    if direction == 0 {
        if abs(cur - object) <= y - x || y == 0 {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

fn abs(i:i32) -> i32 {
    if i > 0 {
        i
    } else {
        -i
    }
}