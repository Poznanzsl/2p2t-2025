import { View, Text,Image } from "react-native";
import styles from './styleRecipe.js'



export default function Recipe(props){

    const name = (props.name  ? props.name : "none")
    const time = (props.time  ? props.time : "0")
    const imgSrc = (props.imgSrc  ? props.imgSrc : require("../assets/Recipes/defaultRecipe.png"))
    
    return(
        <View style= {styles.box}>
            <View>
                <Text style={styles.name}>{name}</Text>
                <Text style={styles.time}>•time:{time}</Text>
            </View>
           <Image source={imgSrc} style={styles.img}></Image>
        </View>
    );
}

