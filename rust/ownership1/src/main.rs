
fn main() {
    let rect = Rect::new(10.0, 10.0);

    println!("area: {}", rect.area());

    dbg!(&rect);
}

#[derive(Debug)]
struct Rect {
    width: f32,
    height: f32,
}

impl Rect {
    fn new(
        width: f32,
        height: f32
    ) -> Rect {
        Rect { width, height }
    }

    fn area(&self) -> f32 {
        self.height * self.width
    }
}