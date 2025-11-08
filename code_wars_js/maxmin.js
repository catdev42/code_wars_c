function highAndLow(numbers) {
	let arr = numbers.split(" ");
	let intArr = arr.map((num) => Number(num));
	intArr.sort((a, b) => a - b);
	return [intArr[intArr.length - 1], intArr[0]].join(" ");
}
