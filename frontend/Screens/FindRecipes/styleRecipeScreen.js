import { StyleSheet } from "react-native";
import { Colors } from "../../assets/cssVariables";

export default StyleSheet.create({
    container:{
        display:'flex',
        width:'100%',
        height:'100%',
        backgroundColor:Colors.white,
        flexDirection:'column',
    },
    header:{
        fontWeight:900,
        color:Colors.yellow,
        fontSize:40,
        marginTop:'2%',
        marginLeft: 'auto',
        marginRight: 'auto',
    },
    time:{
        marginTop:'5%',
        marginLeft:'1%',
        fontSize:20,
        color:Colors.darkGreen,
    }
})