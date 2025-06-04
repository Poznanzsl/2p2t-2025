import { StyleSheet } from "react-native"
import { Colors } from "../../assets/cssVariables";

export default StyleSheet.create({
    container:{
        display:'flex',
        width:'100%',
        height:'100%',
        backgroundColor:Colors.white,
        flexDirection:'column',
        flex:1,
    },
    header:{
        fontWeight:900,
        color:Colors.yellow,
        fontSize:40,
        marginTop:'2%',
        textAlign: 'center',
    },
    time:{
        marginTop:'6%',
        marginLeft:'3%',
        fontSize:25,
        color:Colors.darkGreen,
    },
    skladniki:{
        marginTop:'6%',
        marginLeft:'3%',
        fontSize: 25,
        color:Colors.darkGreen,
    },
    opis:{
        marginTop:'6%',
        marginLeft:'3%',
        fontSize: 25,
        color:Colors.darkGreen,
    },
    fotos:{
        marginTop:'3%',
        alignItems:'center',
        width: '100%',
        height: 400,
        resizeMode: 'cover',
    }
});