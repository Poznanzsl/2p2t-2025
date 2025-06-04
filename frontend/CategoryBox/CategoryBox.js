import { View , Text, Pressable} from "react-native";
import styles from './styleCategoryBox.js';
import { useNavigation } from "@react-navigation/native";

export default function CategoryBox(prop){

    const type = (prop.type? prop.type : "none");
    const emoji = (prop.emoji? prop.emoji : "❌");

    const navigation = useNavigation();

    return(
        <Pressable style={styles.box} onPress={()=> navigation.navigate("Category",{"type" : type })}> 
            <Text style={styles.emoji}>{emoji}</Text>
            <Text style={styles.text}>{type}</Text>
        </Pressable>
    );
}