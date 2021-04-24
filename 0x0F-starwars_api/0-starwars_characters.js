#!/usr/bin/node
const request = require('request');
let myArgs = process.argv.slice(2);

let url = 'https://swapi-api.hbtn.io/api/films/' + myArgs[0];
let options = {json: true};

request(url, options, (error, res, body) => {
    if (error) {
        return  console.log(error)
    };
    if (!error && res.statusCode == 200) {
        let results = body.characters;

        for (let i = 0; i < results.length; i++) {
            request(results[i], options, (error1, res1, body1) => {
                if (!error1 && res1.statusCode == 200) {
                  console.log(body1.name)
                }
            });
        }
        
    };
});