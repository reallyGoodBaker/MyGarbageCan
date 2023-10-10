use rand::Rng;

fn min_max(nums: &Vec<i32>) -> (i32, i32, u16) {
    let mut min = nums[0];
    let mut max = nums[0];
    let mut swap_times = 0u16;

    for num in nums {
        if *num < min {
            swap_times += 1;
            min = *num
        }

        if *num > max {
            swap_times += 1;
            max = *num
        }
    }

    (min, max, swap_times)
}

fn calc_once() -> u16 {
    let mut rng = rand::thread_rng();
    let mut nums: Vec<i32> = Vec::new();

    for _ in 0..10 {
        let num: i32 = rng.gen_range(1..20);
        nums.push(num)
    }

    let result = min_max(&nums);

    println!(
        "nums: {:?}\nmin and max: {:?}\nswap times: {}\n",
        nums,
        (result.0, result.1),
        result.2
    );

    result.2
}

fn main() {
    let mut total: u16 = 0;

    for _ in 0..10 {
        total += calc_once()
    }

    println!("avg: {}", (total as f32) / 10f32)
}
