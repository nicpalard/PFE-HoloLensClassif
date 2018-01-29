var express = require('express');
var router = express.Router();
const fs = require('fs');
const dxt = require('dxt');

// middleware that is specific to this router
router.use(function timeLog (req, res, next) {
  console.log('Time: ', Date.now());
  next();
});


// define the home page route
// Will return all the documents
router.get('/',function (req, res) {
  console.log('document - get - /');
  res.status(500).send({ error: 'something blew up' });
});

// Try to find a match for the given document in the DB
router.get('/match', function (req, res) {
  console.log('document - get - /match');
  res.status(500).send({ error: 'something blew up' });
});

// Get all the linked documents for a given document
router.get('/link', function (req, res) {
  console.log('document - get - /link');
  res.status(500).send({ error: 'something blew up' });
});

// Add a new document into the database
router.post('/new', function (req, res) {
    console.log('document - post - /new');
    let body = [];

    req.on('data', function (chunk) {
        body.push(chunk);
    });

    req.on('end', function () {
        body = Buffer.concat(body);

        fs.writeFile('test.png', body, 'binary', function (err, written) {
            if (err) {
                console.log(err);
            } else {
                console.log("Successfully written");
            }
        });

        res.status(500).send({ error: 'something blew up' });
    });
});

// Update a document of the database
router.post('/update', function (req, res) {
  console.log('document - post - /update');
  res.status(500).send({ error: 'something blew up' });
});

// Add a link between two documents
router.post('/link', function (req, res) {
  console.log('document - post - /link');
  res.status(500).send({ error: 'something blew up' });
});



module.exports = router;
