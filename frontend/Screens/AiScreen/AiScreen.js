
import { StatusBar } from 'expo-status-bar';
import { Pressable, StyleSheet, Text, View } from 'react-native';

import styles from '../AiScreen/styleAiScreen.js'
import NavigationBar from '../../NavigationBar/NavigationBar';


export default function AiScreen() {

  async function generateRecipe(){
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


 }                           


  return (
    <View style={styles.container}>
      <Text>ai tworzy przepisy</Text>
      <Pressable style = {styles.button} onPress={() => generateRecipe()}> 
        <Text>generuj</Text> 
      </Pressable>
      <StatusBar style="auto" />
      <NavigationBar/>
    </View>
  );
}
                                          
