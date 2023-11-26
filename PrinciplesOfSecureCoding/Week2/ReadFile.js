const fs = require("fs");

fs.open("./testFile.txt", "r", async (err, fd) => {
    if (err) {
        console.log(err, "err")
        return
    } 
    else {
        console.log("go change permissions, fast")

        await setTimeout(() => {
            const data = fs.readFileSync('./testFile.txt', { encoding: 'utf8', flag: 'r' });
            console.log(data);
        }, 20000);
    }
})