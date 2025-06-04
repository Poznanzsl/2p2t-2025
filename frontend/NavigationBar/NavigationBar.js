import styles from "./stylesNavigationBar.js"
import { Text, View ,  Pressable, Image } from 'react-native';
import { useNavigation } from "@react-navigation/native";

export default function NavigationBar(){

    const navigation = useNavigation();

    return(
        <View style={styles.bar}>

            <View style={styles.buttonAndTextBox}>
                <Pressable style = {styles.button} onPress={()=> navigation.navigate('home')}>
                    <Image source={require("../assets/NavigationBar/home.png")} style={styles.img}></Image>
                </Pressable>
                <Text style= {styles.text}>menu</Text>
            </View>
            
            <View style={styles.buttonAndTextBox}>
                <Pressable style = {styles.button} onPress={() => navigation.navigate('findRecipes')}>
                    <Image source={require("../assets/NavigationBar/search.png")} style={styles.img}></Image>
                </Pressable>
                <Text style= {styles.text}>szukaj</Text>
            </View>

            <View style={styles.buttonAndTextBox}>
                <Pressable style = {styles.button}  onPress={() => navigation.navigate('Ai')}>
                    <Image source={require("../assets/NavigationBar/ai.png")} style={styles.img}></Image>
                </Pressable>
                <Text style= {styles.text}>AI</Text>
            </View>
            
        </View>
    );

}