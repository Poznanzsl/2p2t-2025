import { View , Text} from "react-native";
import styles from './styleCategoryBox.js';

export default function CategoryBox(prop){

    const type = (prop.type? prop.type : "none");
    const emoji = (prop.emoji? prop.emoji : "❌");

    return(
        <View style={styles.box}> 
            <Text style={styles.emoji}>{emoji}</Text>
            <Text style={styles.text}>{type}</Text>
        </View>
    );
}