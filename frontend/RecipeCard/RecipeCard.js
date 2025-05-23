import { View, Text,Image, Pressable } from "react-native";
import styles from './styleRecipeCard.js'
import { useNavigation } from "@react-navigation/native";



export default function RecipeCard(props){

    const name = (props.name  ? props.name : "none");
    const time = (props.time  ? props.time : "0");
    const imgSrc = (props.imgSrc  ? props.imgSrc : require("../assets/Recipes/defaultRecipe.png"));
    const id = (props.id ?  props.id : 0);

    const navigation = useNavigation();

    // TODO : zrobic baze danych w ktorej beda trzymane zdjecia 
    
    return(
        <Pressable style= {styles.box} onPress={()=> navigation.navigate("Recipe", {id} ) }>
            <View>
                <Text style={styles.name}>{name}</Text>
                <Text style={styles.time}>•czas: {time}min</Text>
            </View>
           <Image source={imgSrc} style={styles.img}></Image>
        </Pressable>
    );
}

