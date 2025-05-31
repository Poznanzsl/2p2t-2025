
import { StatusBar } from 'expo-status-bar';
import { Pressable, StyleSheet, Text, View } from 'react-native';

import styles from '../AiScreen/styleAiScreen.js'
import NavigationBar from '../../NavigationBar/NavigationBar';
import { useEffect, useState } from 'react';

import RecipeCard from '../../RecipeCard/RecipeCard.js';


export default function AiScreen() {

  let [recipeData , setRecipeData] = useState();
  let [isThereRecipe , setIsThereRecipe] = useState(false);

  async function generateRecipe(){
    console.log("elo");
   let respond = await fetch("https://maniowy.lm.r.appspot.com/api");
   respond = await respond.json();
      
   // const cleanResponse = respond.data.substring(8,respond.data.length - 5 );

    const cleanResponse = respond.data;
    let recipe;
    do{
      try{
      recipe = JSON.parse(cleanResponse);
      }
      catch{
        console.log("error");
      }

    }while( recipe == undefined)

    console.log(recipe);
    setRecipeData(recipe);
    setIsThereRecipe(true);
 }                           


  return (
    <>
      {!isThereRecipe &&  (
       <View style={styles.container}>
        <Pressable style = {styles.button} onPress={() => generateRecipe()}> 
          <Text>generuj</Text> 
        </Pressable>
        <StatusBar style="auto" />
        <NavigationBar/>
      </View>)}


      {isThereRecipe &&
        <View style={styles.container}>

          <Text style ={styles.header}>{recipeData.name}</Text>
          <Text style={styles.time}>• czas : {recipeData.time}min</Text>

          <Pressable style = {styles.button} onPress={generateRecipe}> 
            <Text>generuj</Text> 
          </Pressable>
          <NavigationBar/>
        </View>
      }
    </>
  );
}
                                          
