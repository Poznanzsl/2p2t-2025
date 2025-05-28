
if (process.env.NODE_ENV !== 'production') {
  require('dotenv').config();
  const fetch = require('node-fetch'); 
  
}

const express = require('express');
const app = express();

const PORT = process.env.PORT;
console.log(PORT);

app.get('/api', async (req, res) => {
  const key = process.env.API_KEY;
 
    const endpoint = `https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=${key}`;

    const query ={
      contents:[
        {
          parts:[{text:'generate ONE recipie in format be creative but dont change format dont add anythink else!: {"id": must be 0,"name": ,"time": ,"type": }'} ]
        }
      ]
    }


    const respons = await fetch(endpoint,{
      method:'POST',
      headers:{
        "Content-Type": "application/json"
      },
      body:JSON.stringify(query)
    })


    const data = await respons.json();
    const text = data?.candidates?.[0]?.content?.parts?.[0]?.text;


  res.json({ data: text });
});

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});