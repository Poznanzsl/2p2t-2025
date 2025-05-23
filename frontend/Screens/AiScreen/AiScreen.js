
import { StatusBar } from 'expo-status-bar';
import { Pressable, StyleSheet, Text, View } from 'react-native';

import styles from '../AiScreen/styleAiScreen.js'
import NavigationBar from '../../NavigationBar/NavigationBar';


export default function AiScreen() {

  async function generateRecipe(){

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
                                          
