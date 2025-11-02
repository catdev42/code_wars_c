function sumItUp(numbersWithBases) {
	let ret = numbersWithBases.reduce((acc, memb) => acc + parseInt(memb[0], memb[1]), 0);
	return ret;
}
