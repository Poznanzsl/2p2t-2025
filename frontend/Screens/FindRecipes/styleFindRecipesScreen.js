import { StyleSheet } from "react-native"
import { Colors } from "../../assets/cssVariables"

export default StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: Colors.white,
        width:'100%',
        height:'100%',
     },

     scrollView:{
        marginTop:'5%',
        width:'100%',
     },
      row:{
        width:'100%',
        display:'flex',
        flexDirection:'row',
    },
     
})