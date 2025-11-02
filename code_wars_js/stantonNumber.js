function stantonMeasure(a) {
	let ones = a.reduce((acc, num) => (num == 1 ? acc + 1 : acc), 0);
	console.log(ones);
	let stanton = a.reduce((acc, num) => (num == ones ? acc++ : acc), 0);
	return stanton;
}
