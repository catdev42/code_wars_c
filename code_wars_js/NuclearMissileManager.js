function delay(ms) {
	return new Promise((resolve) => setTimeout(resolve, ms));
}

async function launchAll(launchMissile) {
	for (var i = 0; i < 5; i++) {
		launchMissile(i);
		let check = await delay(1000);
	}
}

//other
// function launchAll(launchMissile) {
//   for(let i = 0; i < 5; i++) {
//     setTimeout(function() {
//       launchMissile(i);
//     }, i * 1000);
//   }
// }

// other
// function launchAll(launchMissile) {
//   for (var i = 0; i < 5; i++) {
//     (function(i) {
//       setTimeout(() => {
//         launchMissile(i);
//       }, i * 1000);
//     })(i);
//   }
// }

//by the time the missiles are launching,
//the for loop has finished running and i == 5 :)
//cause for loop is synchronous
